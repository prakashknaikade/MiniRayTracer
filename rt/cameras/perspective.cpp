#include <rt/cameras/perspective.h>

namespace rt {

PerspectiveCamera::PerspectiveCamera(const Point& center, const Vector& forward, const Vector& up, float verticalOpeningAngle, float horizontalOpeningAngle)
{
    /* TODO */
    PerspectiveCamera::center = center;
  	PerspectiveCamera::forward = forward;
  	PerspectiveCamera::up = up;
    PerspectiveCamera::verticalOpeningAngle = verticalOpeningAngle;
    PerspectiveCamera::horizontalOpeningAngle = horizontalOpeningAngle;

    PerspectiveCamera::cutX = tan(PerspectiveCamera::horizontalOpeningAngle/2.0f);
    PerspectiveCamera::cutY = tan(PerspectiveCamera::verticalOpeningAngle/2.0f);

    PerspectiveCamera::CamZ = PerspectiveCamera::forward.normalize();
    PerspectiveCamera::CamX = cross(PerspectiveCamera::forward, PerspectiveCamera::up.normalize()).normalize();
    PerspectiveCamera::CamY = cross(PerspectiveCamera::CamXAxis, PerspectiveCamera::CamZAxis).normalize();

}

Ray PerspectiveCamera::getPrimaryRay(float x, float y) const {
    /* TODO */ NOT_IMPLEMENTED;
}
	Vector dir = (x * CamX * cutX + y * CamYAxis * cutY +  CamZAxis).normalize();
	return Ray(center, dir);
}
