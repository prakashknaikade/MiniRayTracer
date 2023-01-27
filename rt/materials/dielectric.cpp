#include <rt/materials/dielectric.h>
#include <core/random.h>

namespace rt {

DielectricMaterial::DielectricMaterial(float eta)
{
    /* TODO */

    this->eta = eta;

}

RGBColor DielectricMaterial::getReflectance(const Point& texPoint, const Vector& normal, const Vector& outDir, const Vector& inDir) const {

    /* TODO */ 

    return(RGBColor::rep(0.0f));

}

RGBColor DielectricMaterial::getEmission(const Point& texPoint, const Vector& normal, const Vector& outDir) const {
    
    /* TODO */ 

    return(RGBColor::rep(0.0f));
}

Material::SampleReflectance DielectricMaterial::getSampleReflectance(const Point& texPoint, const Vector& normal, const Vector& outDir) const {

    /* TODO */ 

    float r_parallel_2, r_perpendicular_2;
    float cos_theta_t = dot(normal, outDir);
    float inv_eta = eta;
    Vector normal_hit = normal;

    if (cos_theta_t > 0) {
        inv_eta = 1 / eta;
    }
    else {
        cos_theta_t = -cos_theta_t;
        normal_hit = -normal;
    }

    float sin_theta_i = inv_eta * sqrt(1 - pow(cos_theta_t, 2));
    Vector reflection_dir = (-outDir + 2 * dot(outDir, normal_hit) * normal_hit).normalize();
    if (sin_theta_i > 1) {
        return(Material::SampleReflectance(reflection_dir, RGBColor::rep(1.0f)));
    }
    float cos_theta_i = sqrt(1 - pow(inv_eta, 2) * (1 - pow(cos_theta_t, 2)));
    r_parallel_2 = (inv_eta * cos_theta_i - cos_theta_t) / (inv_eta * cos_theta_i + cos_theta_t);
    r_perpendicular_2 = (cos_theta_i - inv_eta * cos_theta_t) / (cos_theta_i + inv_eta * cos_theta_t);
    float fr = (r_parallel_2 * r_parallel_2 + r_perpendicular_2 * r_perpendicular_2) / 2;

    if (random() < fr) {
        return(Material::SampleReflectance(reflection_dir, RGBColor::rep(1.0f)));
    }

    else {
        Vector refraction_dir = (inv_eta * cos_theta_t - cos_theta_i) * normal_hit - inv_eta * outDir;
        return(Material::SampleReflectance(refraction_dir.normalize(), RGBColor::rep(1.0f)));
    }
}

Material::Sampling DielectricMaterial::useSampling() const {
    /* TODO */ 
    return SAMPLING_ALL;
}

}