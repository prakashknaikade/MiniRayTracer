#include <rt/solids/triangle.h>

namespace rt {

Triangle::Triangle(Point vertices[3], CoordMapper* texMapper, Material* material)
{
    /* TODO */
}

Triangle::Triangle(const Point& v1, const Point& v2, const Point& v3, CoordMapper* texMapper, Material* material)
{
    /* TODO */
    Triangle::v1 = v1;
    Triangle::v2 = v2;
    Triangle::v3 = v3;
    Triangle::normal = cross((v2 - v1), (v3 - v1)).normalize();
}

BBox Triangle::getBounds() const {
    /* TODO */ NOT_IMPLEMENTED;
}

Intersection Triangle::intersect(const Ray& ray, float tmin, float tmax) const {
    /* TODO */ //NOT_IMPLEMENTED;
    if (dot(ray.d, this->normal) == 0.0) 
        return Intersection::failure();
    
    float t = - dot(ray.o - v1, normal) / dot(ray.d, this->normal);
	if (t > previousBestDistance || t < epsilon) 
        return Intersection::failure();

  Vector m1 = v2 - v1;
  Vector m2 = v3 - v1;
  Vector pvec = cross(ray.d, m2);
  float det = dot(m1, pvec);

  if (fabs(det) < epsilon)
    return Intersection::failure();

  float invDet = 1.0 / det;
  Vector tvec = ray.o - v1;

  float u = dot(tvec, pvec) * invDet;

  if (u < 0 || u > 1)
    return Intersection::failure();

  Vector qvec = cross(tvec, m1);
  float v = dot(ray.d, qvec) * invDet;

  if (v < 0 || u + v > 1)
    return Intersection::failure();

  t = dot(m2, qvec) * invDet;
  return Intersection(t, ray, this, normal, Point(1-u-v, u, v));
}

Solid::Sample Triangle::sample() const {
    /* TODO */ NOT_IMPLEMENTED;
}

float Triangle::getArea() const {
    /* TODO */ NOT_IMPLEMENTED;
    return cross(v2 - v1, v3 - v1).length() / 2;
}

}