#include <rt/materials/lambertian.h>
#include <rt/textures/texture.h>
#include <core/scalar.h>

namespace rt {

LambertianMaterial::LambertianMaterial(Texture* emission, Texture* diffuse)
{
    /* TODO */
    this->emission = emission;
    this->diffuse = diffuse;
}

RGBColor LambertianMaterial::getReflectance(const Point& texPoint, const Vector& normal, const Vector& outDir, const Vector& inDir) const {
    // CG_UNUSED(texPoint);
    // CG_UNUSED(normal);
    // CG_UNUSED(outDir);
    // CG_UNUSED(inDir);

    // /* TODO */ NOT_IMPLEMENTED;
    return (diffuse->getColor(texPoint) * dot(normal, inDir) / pi);
}

RGBColor LambertianMaterial::getEmission(const Point& texPoint, const Vector& normal, const Vector& outDir) const {
    // CG_UNUSED(texPoint);
    // CG_UNUSED(normal);
    // CG_UNUSED(outDir);

    // /* TODO */ NOT_IMPLEMENTED;
    return (emission->getColor(texPoint) * dot(normal, outDir));
}

Material::SampleReflectance LambertianMaterial::getSampleReflectance(const Point& texPoint, const Vector& normal, const Vector& outDir) const {
    CG_UNUSED(texPoint);
    CG_UNUSED(normal);
    CG_UNUSED(outDir);
	UNREACHABLE;
}

Material::Sampling LambertianMaterial::useSampling() const {
	return SAMPLING_NOT_NEEDED;
}

}