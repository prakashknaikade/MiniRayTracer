#include <rt/bbox.h>
#include <rt/primitive.h>
#include <rt/ray.h>
#include <algorithm>

using namespace std;

namespace rt {

BBox BBox::empty() {
    // /* TODO */ NOT_IMPLEMENTED;
    BBox newBBox;
    newBBox.IsEmpty = true;
    return newBBox;
}

BBox BBox::full() {
    // /* TODO */ NOT_IMPLEMENTED;
    BBox newBBox;
    newBBox.min = Point(-FLT_MAX, -FLT_MAX, -FLT_MAX);
    newBBox.max = Point(FLT_MAX, FLT_MAX, FLT_MAX);
    return newBBox;
}


void BBox::extend(const Point& point) {
    // /* TODO */ NOT_IMPLEMENTED;
     if (IsEmpty) {
        IsEmpty = false;
        min = point;
        max = point;
        return;
    }
    min = rt::min(this->min, point);
    max = rt::max(this->max, point);
    return;
}

void BBox::extend(const BBox& bbox) {
    // /* TODO */ NOT_IMPLEMENTED;
    if (IsEmpty) {
        IsEmpty = bbox.IsEmpty;
        min = bbox.min;
        max = bbox.max;
        return;
    }
    min = rt::min(this->min, bbox.min);
    max = rt::max(this->max, bbox.max);
    return;
}

std::pair<float, float> BBox::intersect(const Ray& ray) const {
    // /* TODO */ NOT_IMPLEMENTED;
    // checks and aabox stuff check parallel
    float t0x = (min.x - ray.o.x) / ray.d.x;
    float t1x = (max.x - ray.o.x) / ray.d.x;
    if (t0x > t1x) std::swap(t0x, t1x);

    float t0y = (min.y - ray.o.y) / ray.d.y;
    float t1y = (max.y - ray.o.y) / ray.d.y;
    if (t0y > t1y) std::swap(t0y, t1y);

    float t0z = (min.z - ray.o.z) / ray.d.z;
    float t1z = (max.z - ray.o.z) / ray.d.z;
    if (t0z > t1z) std::swap(t0z, t1z);

    float maxt0 = std::max(std::max(t0x, t0y), t0z);

    float mint1 = std::min(std::min(t1x, t1y), t1z);

    std::pair<float, float> p;
    p = std::make_pair(maxt0, mint1);
    return p;
}

bool BBox::isUnbound() const {
    // /* TODO */ NOT_IMPLEMENTED;
    if (min.x == -FLT_MAX) return true;
    if (min.y == -FLT_MAX) return true;
    if (min.z == -FLT_MAX) return true;

    if (max.x == FLT_MAX) return true;
    if (max.y == FLT_MAX) return true;
    if (max.z == FLT_MAX) return true;

    return false;
}

Point BBox::centroid() const {
  return Point((min.x + max.x)/2, (min.y + max.y)/2, (min.z + max.z)/2);
}

}