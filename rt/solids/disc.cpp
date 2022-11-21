#include <rt/solids/disc.h>

namespace rt {

Disc::Disc(const Point& center, const Vector& normal, float radius, CoordMapper* texMapper, Material* material)
{
    /* TODO */
    this->mOrigin = center;
	this->mNormal = normal.normalize();
	setMaterial(material);
	setCoordMapper(texMapper);
	this->mRadius = radius;
	
}

BBox Disc::getBounds() const {
    /* TODO */ NOT_IMPLEMENTED;
}

Intersection Disc::intersect(const Ray& ray, float tmin, float tmax) const {
    // /* TODO */ NOT_IMPLEMENTED;
    float denom = dot(ray.d, this->mNormal);
	if (denom == 0.0) return Intersection::failure(); 

	float t = -dot(ray.o - mOrigin, mNormal) / denom;

	if (t > tmax || t < tmin) return Intersection::failure();

	Point surfacePoint = ray.getPoint(t);

	if ((surfacePoint - mOrigin).length() > mRadius)
		return Intersection::failure();

	return Intersection(t, ray, this, mNormal, surfacePoint);
}

Solid::Sample Disc::sample() const {
    NOT_IMPLEMENTED;
}

float Disc::getArea() const {
    // /* TODO */ NOT_IMPLEMENTED;
    return pi * mRadius * mRadius;
}

}
