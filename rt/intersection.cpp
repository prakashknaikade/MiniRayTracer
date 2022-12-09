#include <rt/intersection.h>

namespace rt {

Intersection::Intersection(float distance, const Ray& ray, const Solid* solid, const Vector& normal, const Point& local)
{
    /* TODO */
    this->distance = distance;
	this->ray = ray;
	this->solid = solid;
    this->normalVec = normal;
    this->localPoint = local;
    this->Intersection_Status = true;
}

Intersection::operator bool() const {
    /* TODO */ //NOT_IMPLEMENTED;
    return(this->Intersection_Status);
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
    return (this->ray.getPoint(this->distance));
}

Vector Intersection::normal() const {
    /* TODO */ //NOT_IMPLEMENTED;
    return (this->normalVec);
}

Point Intersection::local() const {
    /* TODO */ //NOT_IMPLEMENTED;
    return this->localPoint;
}

}
