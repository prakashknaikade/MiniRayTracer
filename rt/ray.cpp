#include <core/assert.h>
#include <core/macros.h>
#include <rt/ray.h>

namespace rt {

Ray::Ray(const Point& o, const Vector& d)
{
    rt_assert(d != Vector::rep(0.0f));
}

Point Ray::getPoint(float distance) const {
    /* TODO */ //NOT_IMPLEMENTED;
    Vector normalized = Ray::d.normalize();
    Point out =  Ray::o + (distance * normalized);
    return out;
}

}
