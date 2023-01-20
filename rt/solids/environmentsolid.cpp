#include <rt/solids/environmentsolid.h>
#include <rt/coordmappers/world.h>
#include <core/homogeneouscoord.h>

namespace rt{

EnvironmentSolid::EnvironmentSolid(CoordMapper *texMapper, Material *material) : Solid(texMapper, material) {
}

Intersection EnvironmentSolid::intersect(const rt::Ray &ray, float tmin = 0, float tmax = FLT_MAX) const {
    return Intersection(FLT_MAX/10, ray, this, ray.d, Point::rep(0.0f));
}

BBox EnvironmentSolid::getBounds() const {
    return BBox::full();
}

float EnvironmentSolid::getArea() const {
    return FLT_MAX;
}

Solid::Sample EnvironmentSolid::sample() const {
    NOT_IMPLEMENTED;
}

};
