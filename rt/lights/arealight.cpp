#include <rt/lights/arealight.h>
#include <rt/solids/solid.h>
#include <rt/materials/material.h>
#include <core/color.h>
#include <core/homogeneouscoord.h>

namespace rt {

LightHit AreaLight::getLightHit(const Point& p) const {
    // /* TODO */ NOT_IMPLEMENTED;
    LightHit hit;
    Solid::Sample s = source->sample();
    hit.direction = s.point - p;
    hit.distance = hit.direction.length();
    hit.direction = hit.direction.normalize();
    hit.normal = s.normal;
    return(hit);
}

RGBColor AreaLight::getIntensity(const LightHit& irr) const {
    // /* TODO */ NOT_IMPLEMENTED;
    RGBColor intensity = source->material->getEmission(Point::rep(0.0f), irr.normal, -irr.direction) * area;
    return intensity / pow(irr.distance, 2);
}

AreaLight::AreaLight(Solid* source)
{
    /* TODO */
    this->source = source;
    this->area = source->getArea();
}

}