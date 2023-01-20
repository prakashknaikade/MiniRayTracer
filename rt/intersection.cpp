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
    // if (this->Intersection_Status == false) rt_assert(this->solid == nullptr);
    return(this->Intersection_Status);
}

Intersection Intersection::failure() {
    /* TODO */ //NOT_IMPLEMENTED;
    Intersection failedIntersection;
	failedIntersection.Intersection_Status = false;
    // failedIntersection.solid = nullptr;
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
