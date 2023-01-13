#include <rt/lights/spotlight.h>

namespace rt {

SpotLight::SpotLight(const Point& position, const Vector& direction, float angle, float power, const RGBColor& intensity)
{
    /* TODO */
    this->light_position = position;
    this->conic_dir = direction.normalize();
    this->conic_angle = angle;
    this->cosine_exp = power;
    this->light_intensity = intensity;
}

RGBColor SpotLight::getIntensity(const LightHit& irr) const {
    // /* TODO */ NOT_IMPLEMENTED;
    float cos_theta = dot(conic_dir, -irr.direction);
    if (cos_theta - cos(conic_angle) > 0) {
        return(light_intensity*pow(cos_theta,cosine_exp) / (irr.distance * irr.distance));
        // return(light_intensity * cos_theta);
    }
    else {
        return(RGBColor::rep(0.0f));
    }
}

}
