#include <rt/integrators/casting.h>
#include <rt/intersection.h>
#include <rt/world.h>

namespace rt {

RGBColor RayCastingIntegrator::getRadiance(const Ray& ray) const {
    /* TODO */ //NOT_IMPLEMENTED;
    Intersection intersection = world->scene->intersect(ray);
    if(intersection) {
        // RGBColor::rep(max(dot(-ray.d.normalize(), intersection.normal()), 0.f))
        // //-1.0f * dot(ray.d.normalize(), intersection.normal()); 
        float grey_value = max(dot(-ray.d.normalize(), intersection.normal()), 0.f); 
        return RGBColor::rep(grey_value).clamp();
    }
    else{
        return RGBColor(0,0,0);
    }
}

}
