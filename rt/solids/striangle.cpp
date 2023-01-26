#include <rt/solids/striangle.h>
#include <rt/intersection.h>

namespace rt {

SmoothTriangle::SmoothTriangle(Point vertices[3], Vector normals[3], CoordMapper* texMapper, Material* material)
{
    /* TODO */
    triangle = Triangle(vertices, texMapper, material);
    this->normals[0] = normals[0];
    this->normals[1] = normals[1];
    this->normals[2] = normals[2];
}

SmoothTriangle::SmoothTriangle(const Point& v1, const Point& v2, const Point& v3, const Vector& n1, const Vector& n2, const Vector& n3, CoordMapper* texMapper, Material* material)
{
    /* TODO */
    triangle = Triangle(v1, v2, v3, texMapper, material);
    this->normals[0] = n1;
    this->normals[1] = n2;
    this->normals[2] = n3;
}

Intersection SmoothTriangle::intersect(const Ray& ray, float tmin, float tmax) const {
    // /* TODO */ NOT_IMPLEMENTED;
    Intersection hit = triangle.intersect(ray, tmin, tmax);
    Point bary = hit.local();
    hit.normalVec = bary.x * normals[0] + bary.y * normals[1] + bary.z * normals[2];
    return hit;
}

}