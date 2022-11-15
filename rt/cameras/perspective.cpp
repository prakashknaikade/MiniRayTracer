#include <rt/cameras/perspective.h>
#include <cmath>

namespace rt {

PerspectiveCamera::PerspectiveCamera(const Point& center, const Vector& forward, const Vector& up, float verticalOpeningAngle, float horizontalOpeningAngle)
{
    /* TODO */
    Point _center = center;
  	// PerspectiveCamera::forward = forward;
  	// PerspectiveCamera::up = up;
    // PerspectiveCamera::verticalOpeningAngle = verticalOpeningAngle;
    // PerspectiveCamera::horizontalOpeningAngle = horizontalOpeningAngle;

    float cutX = tan(horizontalOpeningAngle/2.0f);
    float cutY = tan(verticalOpeningAngle/2.0f);

    Vector CamZAxis = forward.normalize();
    Vector CamXAxis = cross(forward, up.normalize()).normalize();
    Vector CamYAxis = cross(CamXAxis, CamZAxis).normalize();

}

Ray PerspectiveCamera::getPrimaryRay(float x, float y) const {
    /* TODO */ //NOT_IMPLEMENTED;
    Vector dir = (x * CamXAxis * cutX + y * CamYAxis * cutY +  CamZAxis).normalize();
	  return Ray(_center, dir);
}
	
}
