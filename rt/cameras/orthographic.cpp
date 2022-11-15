#include <rt/cameras/orthographic.h>
#include <rt/ray.h>

namespace rt {

OrthographicCamera::OrthographicCamera(const Point& center, const Vector& forward, const Vector& up, float scaleX, float scaleY)
{
    /* TODO */
    OrthographicCamera::center = center;
    OrthographicCamera::forward = forward;
    OrthographicCamera::up = up;
    OrthographicCamera::scaleX = scaleX;
    OrthographicCamera::scaleY = scaleY;
    OrthographicCamera::CamZAxis = OrthographicCamera::forward.normalize();
    OrthographicCamera::CamXAxis = cross(OrthographicCamera::CamZAxis, OrthographicCamera::up.normalize()).normalize();
    OrthographicCamera::CamYAxis = cross(OrthographicCamera::CamXAxis, OrthographicCamera::CamZAxis).normalize();
}

Ray OrthographicCamera::getPrimaryRay(float x, float y) const {
    /* TODO */ //NOT_IMPLEMENTED;
    Point o = OrthographicCamera::center + (x * OrthographicCamera::scaleX / 2.0f * OrthographicCamera::CamXAxis + y * OrthographicCamera::scaleY  / 2.0f * OrthographicCamera::CamYAxis);
    return Ray(o, this->forward);
}

}
