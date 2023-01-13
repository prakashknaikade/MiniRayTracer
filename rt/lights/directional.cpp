#include <rt/lights/directional.h>
#include <core/scalar.h>
#include <core/vector.h>

namespace rt {

DirectionalLight::DirectionalLight(const Vector& direction, const RGBColor& color)
{
    /* TODO */
    this->light_dir = direction.normalize();
    this->light_color = color;
}

LightHit DirectionalLight::getLightHit(const Point& p) const {
    CG_UNUSED(p);
    // /* TODO */ NOT_IMPLEMENTED;
    LightHit hit;
    hit.direction = -light_dir;
    hit.distance = FLT_MAX;
    hit.normal = -light_dir;
    return hit;

}

RGBColor DirectionalLight::getIntensity(const LightHit& irr) const {
    CG_UNUSED(irr);
    // /* TODO */ NOT_IMPLEMENTED;
    return(light_color);

}

}
