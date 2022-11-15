#include <rt/cameras/perspective.h>
#include <cmath>

namespace rt {

PerspectiveCamera::PerspectiveCamera(const Point& center, const Vector& forward, const Vector& up, float verticalOpeningAngle, float horizontalOpeningAngle)
{
    /* TODO */
    _center = center;
  	// PerspectiveCamera::forward = forward;
  	// PerspectiveCamera::up = up;
    // PerspectiveCamera::verticalOpeningAngle = verticalOpeningAngle;
    // PerspectiveCamera::horizontalOpeningAngle = horizontalOpeningAngle;

    cutX = tan(horizontalOpeningAngle/2.0f);
    cutY = tan(verticalOpeningAngle/2.0f);

    CamZAxis = forward.normalize();
    CamXAxis = cross(forward, up.normalize()).normalize();
    CamYAxis = cross(CamXAxis, CamZAxis).normalize();

}

Ray PerspectiveCamera::getPrimaryRay(float x, float y) const {
    /* TODO */ //NOT_IMPLEMENTED;
    Vector dir = (x * CamXAxis * cutX + y * CamYAxis * cutY +  CamZAxis).normalize();
	  return Ray(_center, dir);
}
	
}
