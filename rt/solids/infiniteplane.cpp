#include <rt/solids/infiniteplane.h>

namespace rt {

InfinitePlane::InfinitePlane(const Point& origin, const Vector& normal, CoordMapper* texMapper, Material* material)
{
    /* TODO */
    InfinitePlane::origin = origin;
    InfinitePlane::normal = normal;
}

BBox InfinitePlane::getBounds() const {
    /* TODO */ NOT_IMPLEMENTED;
}

Intersection InfinitePlane::intersect(const Ray& ray, float tmin, float tmax) const {
    /* TODO */ NOT_IMPLEMENTED;
    if (dot(ray.d, InfinitePlane::normal) == 0.0) 
        return Intersection::failure();
	
    float t = - dot(ray.o - origin, normal) / dot(ray.d, InfinitePlane::normal);
	if (t > tmax || t < 0) 
        return Intersection::failure();
	
    return Intersection(t, ray, this, InfinitePlane::normal, ray.getPoint(t));
}

Solid::Sample InfinitePlane::sample() const {
    /* TODO */ NOT_IMPLEMENTED;
}

float InfinitePlane::getArea() const {
    /* TODO */ //NOT_IMPLEMENTED;
    return FLT_MAX;
}

}
