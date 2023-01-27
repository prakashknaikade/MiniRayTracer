#include <rt/cameras/dofperspective.h>
#include <rt/ray.h>
#include <math.h>
#include <core/scalar.h>
#include <core/random.h>

namespace rt {

DOFPerspectiveCamera::DOFPerspectiveCamera(const Point& center, const Vector& forward, const Vector& up, float verticalOpeningAngle, float horizontalOpeningAngle, float focalDistance, float apertureRadius)
{
    /* TODO */
    this->center = center;
    this->forward = forward;
    this->up = up;
    this->verticalOpeningAngle = verticalOpeningAngle;
    this->horizontalOpeningAngle = horizontalOpeningAngle;

    this->scaleX = tan(this->horizontalOpeningAngle/2.0f);
    this->scaleY = tan(this->verticalOpeningAngle/2.0f);

    this->CamZAxis = this->forward.normalize();
    this->CamXAxis = cross(this->forward, this->up.normalize()).normalize();
    this->CamYAxis = cross(this->CamXAxis, this->CamZAxis).normalize();

    this->focaldist = focalDistance;
    this->aperture = apertureRadius;
}

Ray DOFPerspectiveCamera::getPrimaryRay(float x, float y) const {
    /* TODO */ 
    Point fp = center + (CamZAxis + x * CamXAxis * scaleX + y * CamYAxis * scaleY).normalize() * focaldist;
    float random_aperture = random(0.0f, aperture);
    float theta = 2 * pi * random();
    x = random_aperture * cos(theta);
    y = random_aperture * sin(theta);

    Point o = center + x * CamXAxis + y * CamYAxis;
    Vector d = (fp - o).normalize();

    return Ray(o, d);
}