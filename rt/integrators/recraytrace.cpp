#include <rt/integrators/recraytrace.h>
#include <rt/world.h>
#include <rt/lights/light.h>
#include <rt/materials/material.h>
#include <rt/solids/solid.h>
#include <rt/coordmappers/coordmapper.h>

namespace rt {

RGBColor RecursiveRayTracingIntegrator::getRadiance(const Ray& ray) const {
    return(radiance(ray, 0));
}

RGBColor RecursiveRayTracingIntegrator::radiance(const Ray& ray, int count) const {
    if (count >= 6) {
        return(RGBColor::rep(0));
    }
    Intersection hitPoint = this->world->scene->intersect(ray);
    if (hitPoint) {
        Point local_hit = hitPoint.solid->texMapper->getCoords(hitPoint);
        RGBColor color = hitPoint.solid->material->getEmission(local_hit, hitPoint.normal(), -ray.d);
        Material::Sampling sample = hitPoint.solid->material->useSampling();
        if (sample == Material::Sampling::SAMPLING_ALL || sample == Material::Sampling::SAMPLING_SECONDARY) {
            Material::SampleReflectance sample_reflect = hitPoint.solid->material->getSampleReflectance(local_hit, hitPoint.normal(), -ray.d);
            color = color + sample_reflect.reflectance * radiance(Ray(hitPoint.hitPoint() + sample_reflect.direction * offset, sample_reflect.direction), count + 1);
        }
        if (sample == Material::Sampling::SAMPLING_NOT_NEEDED || sample == Material::Sampling::SAMPLING_SECONDARY) {

            for (std::vector<rt::Light*>::size_type i = 0; i < world->light.size(); i++) {
                LightHit light_hit = world->light[i]->getLightHit(hitPoint.hitPoint());
                if (dot(light_hit.direction, hitPoint.normal()) * dot(-ray.d, hitPoint.normal()) < epsilon) {
                    continue;
                }
                Intersection obstruction_hit = this->world->scene->intersect(Ray(hitPoint.hitPoint() + epsilon*hitPoint.normal(), light_hit.direction));
                if (obstruction_hit) {
                    if (obstruction_hit.distance < light_hit.distance) {
                        continue;
                    }
                }
                color = color + (this->world->light[i]->getIntensity(light_hit) * hitPoint.solid->material->getReflectance(local_hit, hitPoint.normal(), -ray.d, light_hit.direction));
            }

        }
        return(color);
    }
    return(RGBColor::rep(0.0f));
}

}