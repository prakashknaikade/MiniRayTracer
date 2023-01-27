#include <rt/solids/disc.h>
#include <rt/coordmappers/world.h>
#include <core/random.h>

namespace rt {

Disc::Disc(const Point& center, const Vector& normal, float radius, CoordMapper* texMapper, Material* material) : Solid(texMapper, material)
{
    /* TODO */
    this->mOrigin = center;
	this->mNormal = normal.normalize();
	this->mRadius = radius;
	
	float x = sqrt(mNormal.y * mNormal.y + mNormal.z * mNormal.z);
	float y = sqrt(mNormal.x * mNormal.x + mNormal.z * mNormal.z);
	float z = sqrt(mNormal.y * mNormal.y + mNormal.x * mNormal.x);

	Vector e = Vector(x, y, z);
	Point min = mOrigin - mRadius * e;
	Point max = mOrigin + mRadius * e;

	mBBox = BBox(min, max);

	Vector s;
	if (mNormal.x < mNormal.y && mNormal.x < mNormal.z) {
		s = Vector(0, -mNormal.z, mNormal.y).normalize();
	}
	else if (mNormal.y < mNormal.x && mNormal.y < mNormal.z) {
		s = Vector(-mNormal.z, 0, mNormal.x).normalize();
	}
	else {
		s = Vector(-mNormal.y, mNormal.x, 0).normalize();
	}
	Vector t = cross(mNormal, s).normalize();
	m = Matrix::system(s, t, mNormal.normalize());
}

BBox Disc::getBounds() const {
    // /* TODO */ NOT_IMPLEMENTED;
	return mBBox;
}

Intersection Disc::intersect(const Ray& ray, float tmin, float tmax) const {
    // /* TODO */ NOT_IMPLEMENTED;
    float denom = dot(ray.d, this->mNormal);
	if (denom == 0.0) return Intersection::failure(); 

	float t = -dot(ray.o - mOrigin, mNormal) / denom;
	
	if (t > tmax) return Intersection::failure();

	Point surfacePoint = ray.getPoint(t);

	if ((surfacePoint - mOrigin).length() > mRadius)
		return Intersection::failure();

	return Intersection(t, ray, this, mNormal, surfacePoint);
}

Solid::Sample Disc::sample() const {
    // NOT_IMPLEMENTED;
	float u = random(), v = random();
	Point p = m * Point(u * mRadius * cos(2 * pi * v), u * mRadius * sin(2 * pi * v), 0.0f);
	Solid::Sample s;
	s.point = Point(mOrigin.x + p.x, mOrigin.y + p.y, mOrigin.z + p.z);
	s.normal = mNormal;
	return s;
}

float Disc::getArea() const {
    // /* TODO */ NOT_IMPLEMENTED;
    return pi * mRadius * mRadius;
}

}
