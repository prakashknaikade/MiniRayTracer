#include <rt/materials/combine.h>

namespace rt {

CombineMaterial::CombineMaterial()
{
    /* TODO */
    
}

void CombineMaterial::add(Material* m, float w) {
    /* TODO */ 
    materials.push_back(m);
    weights.push_back(w);
}

RGBColor CombineMaterial::getReflectance(const Point& texPoint, const Vector& normal, const Vector& outDir, const Vector& inDir) const {
    /* TODO */ 
    RGBColor reflectance = RGBColor::rep(0.0f);
    for (std::vector<float>::size_type i = 0; i < weights.size(); i++) {
        reflectance = reflectance + weights[i] * materials[i]->getReflectance(texPoint, normal, outDir, inDir);
    }
    return reflectance;
}

RGBColor CombineMaterial::getEmission(const Point& texPoint, const Vector& normal, const Vector& outDir) const {
    /* TODO */ 
    RGBColor emission = RGBColor::rep(0.0f);
    for (std::vector<float>::size_type i = 0; i < weights.size(); i++) {
        emission = emission + weights[i] * materials[i]->getEmission(texPoint, normal, outDir);
    }
    return emission;
}

Material::SampleReflectance CombineMaterial::getSampleReflectance(const Point& texPoint, const Vector& normal, const Vector& outDir) const {
    /* TODO */ 
    Material::SampleReflectance sr;
    for (std::vector<float>::size_type i = 0; i < weights.size(); i++) {
        if (materials[i]->useSampling() == SAMPLING_ALL) {
            sr = materials[i]->getSampleReflectance(texPoint, normal, outDir);
            sr.reflectance = sr.reflectance * weights[i];
            return(sr);
        }
    }
    return(sr);
}

Material::Sampling CombineMaterial::useSampling() const {
    /* TODO */ 
    return(Material::Sampling::SAMPLING_SECONDARY);
}

}