#include <rt/integrators/raytrace.h>
#include <rt/materials/material.h>
#include <rt/solids/solid.h>
#include <rt/world.h>
#include <rt/lights/light.h>

namespace rt {

RGBColor RayTracingIntegrator::getRadiance(const Ray& ray) const {
    /* TODO */ 
    Intersection hitPoint = this->world->scene->intersect(ray);
    if (hitPoint) {
        RGBColor color = hitPoint.solid->material->getEmission(hitPoint.local(), hitPoint.normal(), -ray.d);
        for (int i = 0; i < world->light.size(); i++) {
            LightHit hitLight = world->light[i]->getLightHit(hitPoint.hitPoint());
            if (dot(hitLight.direction, hitPoint.normal()) < epsilon) {
                continue;
            }
            Intersection hitObstruction = this->world->scene->intersect(Ray(hitPoint.hitPoint(), hitLight.direction));
            if(hitObstruction) {
                if (hitObstruction.distance < hitLight.distance) {
                    continue;
                }
            }
            color = color + (this->world->light[i]->getIntensity(hitLight) * hitPoint.solid->material->getReflectance(hitPoint.local(), hitPoint.normal(), -ray.d, hitLight.direction));
        }
        return(color);
    }
    return(RGBColor::rep(0.0f));
}

}