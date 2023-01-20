#include <rt/solids/triangle.h>
#include <rt/coordmappers/world.h>

namespace rt {

Triangle::Triangle(Point vertices[3], CoordMapper* texMapper, Material* material) : Solid(texMapper, material)
{
    /* TODO */

    v1 = vertices[0];
    v2 = vertices[1];
    v3 = vertices[2];

    mVect1 = (v2 - v1).normalize();
    mVect2 = (v3 - v1).normalize();
    mNormal = cross(mVect1, mVect2).normalize();

}

Triangle::Triangle(const Point& v1, const Point& v2, const Point& v3, CoordMapper* texMapper, Material* material) : Solid(texMapper, material)
{
    /* TODO */

    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;

    mVect1 = (v2 - v1).normalize();
    mVect2 = (v3 - v1).normalize();
    mNormal = cross(mVect1, mVect2).normalize();

}

BBox Triangle::getBounds() const {
    // /* TODO */ NOT_IMPLEMENTED;
    Point min = rt::min(rt::min(v1, v2), v3);
    Point max = rt::max(rt::max(v1, v2), v3);
	return BBox(min, max);
}

Intersection Triangle::intersect(const Ray& ray, float tmin, float tmax) const {
    // /* TODO */
    // IMPLEMENTED FROM TUTORIAL: https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/moller-trumbore-ray-triangle-intersection
    if (dot(ray.d, this->mNormal) == 0.0) return Intersection::failure();
        float t = - dot(ray.o - v1, mNormal) / dot(ray.d, this->mNormal);
    if (t > tmax || t < epsilon) return Intersection::failure();

    Vector e1 = v2 - v1;
    Vector e2 = v3 - v1;
    Vector pvec = cross(ray.d, e2);
    float det = dot(e1, pvec);

    if (fabs(det) < epsilon)
        return Intersection::failure();

    float invDet = 1.0 / det;
    Vector tvec = ray.o - v1;

    float u = dot(tvec, pvec) * invDet;

    if (u < 0 || u > 1)
        return Intersection::failure();

    Vector qvec = cross(tvec, e1);
    float v = dot(ray.d, qvec) * invDet;

    if (v < 0 || u + v > 1)
        return Intersection::failure();

    t = dot(e2, qvec) * invDet;
    return Intersection(t, ray, this, mNormal, Point(1-u-v, u, v));
}

Solid::Sample Triangle::sample() const {
    /* TODO */ NOT_IMPLEMENTED;
}

float Triangle::getArea() const {
    // /* TODO */ NOT_IMPLEMENTED;
    Vector norm = cross(v2 - v1, v3 - v1);
    return norm.length() / 2;
}

}