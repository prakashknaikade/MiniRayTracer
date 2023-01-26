#include <rt/materials/phong.h>
#include <rt/textures/texture.h>
#include <core/scalar.h>

namespace rt {

PhongMaterial::PhongMaterial(Texture* specular, float exponent)
{
    /* TODO */
    this->specular = specular;
    this->exponent = exponent;
}

RGBColor PhongMaterial::getReflectance(const Point& texPoint, const Vector& normal, const Vector& outDir, const Vector& inDir) const {
    // CG_UNUSED(texPoint);
    // CG_UNUSED(normal);
    // CG_UNUSED(outDir);
    // CG_UNUSED(inDir);

    // /* TODO */ NOT_IMPLEMENTED;.
    float dot_indir_normal = max(dot(inDir, normal), 0.0f);
    return(specular->getColor(texPoint) * pow(dot((-inDir + 2 * dot_indir_normal * normal).normalize(), outDir.normalize()), exponent)) * dot_indir_normal * (exponent + 2)/(2*pi);
}

RGBColor PhongMaterial::getEmission(const Point& texPoint, const Vector& normal, const Vector& outDir) const {
    // CG_UNUSED(texPoint);
    // CG_UNUSED(normal);
    // CG_UNUSED(outDir);

    // /* TODO */ NOT_IMPLEMENTED;
    return(RGBColor::rep(0));
}

Material::SampleReflectance PhongMaterial::getSampleReflectance(const Point& texPoint, const Vector& normal, const Vector& outDir) const {
    CG_UNUSED(texPoint);
    CG_UNUSED(normal);
    CG_UNUSED(outDir);

	UNREACHABLE;
}

Material::Sampling PhongMaterial::useSampling() const {
	/* TODO */ NOT_IMPLEMENTED;
}

}