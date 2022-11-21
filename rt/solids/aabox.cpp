#include <rt/solids/aabox.h>

namespace rt {

AABox::AABox(const Point& corner1, const Point& corner2, CoordMapper* texMapper, Material* material)
{
    /* TODO */
    AABox::cornerMin = min(corner1, corner2);
    AABox::cornerMax = max(corner1, corner2);
}

BBox AABox::getBounds() const {
    /* TODO */ NOT_IMPLEMENTED;
}

Solid::Sample AABox::sample() const {
    NOT_IMPLEMENTED;
}

float AABox::getArea() const {
    /* TODO */ //NOT_IMPLEMENTED;
    float x = std::abs(cornerMax.x - cornerMin.x);
    float y = std::abs(cornerMax.y - cornerMin.y);
    float z = std::abs(cornerMax.z - cornerMin.z);
    
    return 2 * (x*y + y*z + z*x) ;
}

Intersection AABox::intersect(const Ray& ray, float tmin, float tmax) const {
    /* TODO */ //NOT_IMPLEMENTED;

    Vector near = (minCorner - ray.o) / ray.d;
    Vector far = (maxCorner - ray.o) / ray.d;

    float tMin = max(max(min(near.x, far.x),min(near.y, far.y)),min(near.z, far.z));
    float tMax = min(min(max(near.x, far.x),max(near.y, far.y)),max(near.z, far.z));

    if (tMax < 0 || tMin > tMax || tMax > FLT_MAX)
        return Intersection::failure();
    if (tMin > previousBestDistance || tMin < 0)
        return Intersection::failure();

    Vector normal;
    normal = tMin == near.x ? Vector(-1, 0, 0) : normal;
    normal = tMin == far.x ? Vector(1, 0, 0) : normal;
    normal = tMin == near.y ? Vector(0, -1, 0) : normal;
    normal = tMin == far.y ? Vector(0, 1, 0) : normal;
    normal = tMin == near.z ? Vector(0, 0, -1) : normal;
    normal = tMin == far.z ? Vector(0, 0, 1) : normal;

    return Intersection(tMin, ray, this, normal, ray.getPoint(tMin));
}

}
