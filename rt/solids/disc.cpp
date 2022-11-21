#include <rt/solids/disc.h>

namespace rt {

Disc::Disc(const Point& center, const Vector& normal, float radius, CoordMapper* texMapper, Material* material)
{
    /* TODO */
    Disc::center = center;
	Disc::normal = normal;
	Disc::radius = radius;


	// Vector p;
	// if (normal.x < normal.y && normal.x < normal.z) {
	// 	p = Vector(0, -normal.z, normal.y).normalize();
	// }
	// else if (normal.y < normal.x && normal.y < normal.z) {
	// 	p = Vector(-normal.z, 0, normal.x).normalize();
	// }
	// else {
	// 	p = Vector(-normal.y, normal.x, 0).normalize();
	// }

	// Vector t = cross(normal, p).normalize();
}

BBox Disc::getBounds() const {
    /* TODO */ NOT_IMPLEMENTED;
}

Intersection Disc::intersect(const Ray& ray, float tmin, float tmax) const {
    /* TODO */ //NOT_IMPLEMENTED;
    if (dot(ray.d, Disc::normal) == 0.0) 
        return Intersection::failure();
	
    float t = - dot(ray.o - center, Disc::normal) / dot(ray.d, Disc::normal);
	if (t > tmax || t < 0) 
        return Intersection::failure();

	Point _point = ray.getPoint(t);
	if ((_point - center).length() > radius)
		return Intersection::failure();

	return Intersection(t, ray, this, Disc::normal, _point);
}

Solid::Sample Disc::sample() const {
    NOT_IMPLEMENTED;
}

float Disc::getArea() const {
    /* TODO */ //NOT_IMPLEMENTED;
    float discArea = pi * pow(radius,2);
    return discArea;

}

}
