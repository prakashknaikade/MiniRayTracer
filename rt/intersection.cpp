#include <rt/intersection.h>

namespace rt {

Intersection::Intersection(float distance, const Ray& ray, const Solid* solid, const Vector& normal, const Point& local)
{
    /* TODO */
    Intersection::distance = distance;
	Intersection::ray = ray;
	Intersection::solid = solid;
    Intersection::_normal = normal;
    Intersection::_local = local;
    Intersection::IntersectionOccurred = true;
}

Intersection::operator bool() const {
    /* TODO */ //NOT_IMPLEMENTED;
    return(Intersection_Status);
}

Intersection Intersection::failure() {
    /* TODO */ //NOT_IMPLEMENTED;
    Intersection failedIntersection;
	failedIntersection.Intersection_Status = false;
	return failedIntersection;
}

Point Intersection::hitPoint() const {
    /* TODO */ //NOT_IMPLEMENTED;
    return (Intersection::ray.getPoint(Intersection::distance));
}

Vector Intersection::normal() const {
    /* TODO */ //NOT_IMPLEMENTED;
    return (Intersection::_normal);
}

Point Intersection::local() const {
    /* TODO */ //NOT_IMPLEMENTED;
    return Intersection::_local;
}

}
