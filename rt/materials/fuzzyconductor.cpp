#include <rt/materials/fuzzyconductor.h>
#include <rt/solids/disc.h>

namespace rt {

FuzzyConductorMaterial::FuzzyConductorMaterial(float eta, float kappa, float fuzzyangle)
{
    /* TODO */
    this->eta = eta;
    this->kappa = kappa;
    this->fuzzyangle = fuzzyangle;
    this->eta2_plus_kappa2 = pow(eta, 2) + pow(kappa, 2);
}

RGBColor FuzzyConductorMaterial::getReflectance(const Point& texPoint, const Vector& normal, const Vector& outDir, const Vector& inDir) const {

    /* TODO */ 
    return(RGBColor::rep(0.0f));

}

RGBColor FuzzyConductorMaterial::getEmission(const Point& texPoint, const Vector& normal, const Vector& outDir) const {
    /* TODO */ 
    return(RGBColor::rep(0.0f));
}

Material::SampleReflectance FuzzyConductorMaterial::getSampleReflectance(const Point& texPoint, const Vector& normal, const Vector& outDir) const {
    /* TODO */ 
    float r_parallel_2, r_perpendicular_2;
    Vector reflDir = (-outDir + 2 * dot(outDir, normal) * normal).normalize();
    Disc d = Disc(texPoint + reflDir, reflDir, tan(fuzzyangle), nullptr, nullptr);
    Vector inDir = (d.sample().point - texPoint).normalize();
    float cos_theta_i = dot(normal, inDir);
    r_parallel_2 = (eta2_plus_kappa2 * pow(cos_theta_i, 2) - 2 * eta * cos_theta_i + 1) / (eta2_plus_kappa2 * pow(cos_theta_i, 2) + 2 * eta * cos_theta_i + 1);
    r_perpendicular_2 = (eta2_plus_kappa2 - 2 * eta * cos_theta_i + pow(cos_theta_i, 2)) / (eta2_plus_kappa2 + 2 * eta * cos_theta_i + pow(cos_theta_i, 2));
    Material::SampleReflectance s;
    s.direction = inDir;
    s.reflectance = RGBColor::rep((r_parallel_2 + r_perpendicular_2) / 2);
    return(s);
}

Material::Sampling FuzzyConductorMaterial::useSampling() const {
    /* TODO */ 
    return SAMPLING_ALL;
}

}
