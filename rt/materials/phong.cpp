#include <rt/materials/phong.h>

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
    return(specular->getColor(texPoint) * pow(dot((-inDir + 2 * dot(inDir, normal) * normal).normalize(), outDir.normalize()), exponent)) * dot(inDir, normal) * (exponent + 2)/(2*pi);
}

RGBColor PhongMaterial::getEmission(const Point& texPoint, const Vector& normal, const Vector& outDir) const {
    CG_UNUSED(texPoint);
    CG_UNUSED(normal);
    CG_UNUSED(outDir);

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