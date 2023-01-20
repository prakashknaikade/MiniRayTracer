#include <rt/coordmappers/tmapper.h>
#include <rt/intersection.h>

namespace rt {

TriangleMapper::TriangleMapper(Point ntv[3])
{
    /* TODO */
    this->ntv[0] = HomogeneousCoord(ntv[0]);
    this->ntv[1] = HomogeneousCoord(ntv[1]);
    this->ntv[2] = HomogeneousCoord(ntv[2]);
}

TriangleMapper::TriangleMapper(const Point& tv0, const Point& tv1, const Point& tv2)
{
    /* TODO */
    this->ntv[0] = HomogeneousCoord(tv0);
    this->ntv[1] = HomogeneousCoord(tv1);
    this->ntv[2] = HomogeneousCoord(tv2);

}

Point TriangleMapper::getCoords(const Intersection& hit) const {
    // /* TODO */ NOT_IMPLEMENTED;
    Point local = hit.local();
    HomogeneousCoord texPoint = local.x * ntv[0] + local.y * ntv[1] + local.z * ntv[2];
    return(Point(texPoint));
}

}