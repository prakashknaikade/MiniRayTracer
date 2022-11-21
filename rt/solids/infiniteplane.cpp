#include <rt/solids/infiniteplane.h>

namespace rt {

InfinitePlane::InfinitePlane(const Point& origin, const Vector& normal, CoordMapper* texMapper, Material* material)
{
    /* TODO */
    this->mOrigin = origin;
    this->mNormal = normal.normalize();
    setMaterial(material);
    setCoordMapper(texMapper);

}

BBox InfinitePlane::getBounds() const {
    /* TODO */ NOT_IMPLEMENTED;
}

Intersection InfinitePlane::intersect(const Ray& ray, float tmin, float tmax) const {
    // /* TODO */ NOT_IMPLEMENTED;
    float denom = dot(ray.d, this->mNormal);
    if (fabsf(denom) <= epsilon)
        return Intersection::failure(); 

    float t = -dot(ray.o - mOrigin, mNormal) / denom;

    if (t < tmin || t > tmax) return Intersection::failure();

    
    Point surfacePoint = ray.getPoint(t);
    return Intersection(t, ray, this, mNormal, surfacePoint);
    
}

Solid::Sample InfinitePlane::sample() const {
    /* TODO */ NOT_IMPLEMENTED;
}

float InfinitePlane::getArea() const {
    /* TODO */ //NOT_IMPLEMENTED;
    return FLT_MAX;
}

}
