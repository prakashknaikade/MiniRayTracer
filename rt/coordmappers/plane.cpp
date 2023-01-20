#include <rt/coordmappers/plane.h>
#include <rt/intersection.h>

namespace rt {

PlaneCoordMapper::PlaneCoordMapper(const Vector& e1, const Vector& e2) {
    /* TODO */
    this->transform = Matrix::system(e1, e2, cross(e1, e2)).invert();
}

Point PlaneCoordMapper::getCoords(const Intersection& hit) const {
    // /* TODO */ NOT_IMPLEMENTED;
    return(transform*hit.local());
}

}