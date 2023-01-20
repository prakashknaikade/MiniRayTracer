#include <rt/lights/pointlight.h>

#include <core/vector.h>

namespace rt {

PointLight::PointLight(const Point& position, const RGBColor& intensity)
{
    /* TODO */
    this->lightPosition = position;
    this->lightIntensity = intensity;
}

LightHit PointLight::getLightHit(const Point& p) const {
    /* TODO */ 
    LightHit hit;
    hit.direction = lightPosition - p;
    hit.distance = hit.direction.length();
    hit.direction = hit.direction.normalize();
    hit.normal = hit.direction;
    return(hit);
}

RGBColor PointLight::getIntensity(const LightHit& irr) const {
    /* TODO */ 
    return(lightIntensity / (irr.distance*irr.distance));
}

}
