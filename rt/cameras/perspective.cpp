#include <rt/cameras/perspective.h>
#include <cmath>

namespace rt {

PerspectiveCamera::PerspectiveCamera(const Point& center, const Vector& forward, const Vector& up, float verticalOpeningAngle, float horizontalOpeningAngle)
{
    /* TODO */
    PerspectiveCamera::_center = center;
  	// PerspectiveCamera::forward = forward;
  	// PerspectiveCamera::up = up;
    // PerspectiveCamera::verticalOpeningAngle = verticalOpeningAngle;
    // PerspectiveCamera::horizontalOpeningAngle = horizontalOpeningAngle;

    PerspectiveCamera::cutX = tan(horizontalOpeningAngle/2.0f);
    PerspectiveCamera::cutY = tan(verticalOpeningAngle/2.0f);

    PerspectiveCamera::CamZAxis = forward.normalize();
    PerspectiveCamera::CamXAxis = cross(forward, up.normalize()).normalize();
    PerspectiveCamera::CamYAxis = cross(PerspectiveCamera::CamXAxis, PerspectiveCamera::CamZAxis).normalize();

}

Ray PerspectiveCamera::getPrimaryRay(float x, float y) const {
    /* TODO */ //NOT_IMPLEMENTED;
    Vector dir = (x * PerspectiveCamera::CamXAxis * PerspectiveCamera::cutX + y * PerspectiveCamera::CamYAxis * PerspectiveCamera::cutY +  PerspectiveCamera::CamZAxis).normalize();
	  return Ray(PerspectiveCamera::_center, dir);
}
	
}
