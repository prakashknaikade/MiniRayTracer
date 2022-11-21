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
    /* TODO */ NOT_IMPLEMENTED;
}

}
