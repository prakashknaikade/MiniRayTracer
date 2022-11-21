#include <rt/integrators/casting.h>
#include <rt/intersection.h>
#include <rt/world.h>

namespace rt {

RGBColor RayCastingIntegrator::getRadiance(const Ray& ray) const {
    /* TODO */ //NOT_IMPLEMENTED;
    Intersection intersection = world->scene->intersect(ray);
    if(intersection) {
        float grey_value = -1.0f * dot(ray.d.normalize(), intersection.normal());
        return RGBColor::rep(grey_value).clamp();
    }
    else{
        return RGBColor(0,0,0);
    }
}

}
