#include <rt/intersection.h>

namespace rt {

Intersection::Intersection(float distance, const Ray& ray, const Solid* solid, const Vector& normal, const Point& local)
{
    /* TODO */
    Intersection::distance = distance;
	Intersection::ray = ray;
	Intersection::solid = solid;
    Intersection::normalVec = normal;
    Intersection::localPoint = local;
    Intersection::Intersection_Status = true;
}

Intersection::operator bool() const {
    /* TODO */ //NOT_IMPLEMENTED;
    return(Intersection_Status);
    // return distance != FLT_MAX
}

Intersection Intersection::failure() {
    /* TODO */ //NOT_IMPLEMENTED;
    // failedIntersection = Intersection(FLT_MAX, Ray(), null_ptr (no solid))
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
    return (Intersection::normalVec);
}

Point Intersection::local() const {
    /* TODO */ //NOT_IMPLEMENTED;
    return Intersection::localPoint;
}

}
