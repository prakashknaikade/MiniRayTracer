#include <rt/solids/quad.h>

namespace rt {

Quad::Quad(const Point& origin, const Vector& span1, const Vector& span2, CoordMapper* texMapper, Material* material)
{
    /* TODO */
    setMaterial(material);
    setCoordMapper(texMapper);
    Quad::p1 = origin;
    Quad::span1 = span1;
    Quad::span2 = span2;
    Quad::normal = cross(span1, span2).normalize();

    p2 = p1 + Quad::span1;
    p3 = p1 + Quad::span1 + Quad::span2;
    p4 = p1 + Quad::span2;

    Quad::center = (0.5*Quad::span1) + (0.5*Quad::span2) + p1;

}

BBox Quad::getBounds() const {
    /* TODO */ NOT_IMPLEMENTED;
}

Intersection Quad::intersect(const Ray& ray, float tmin, float tmax) const {
    // /* TODO */ NOT_IMPLEMENTED;
    if (dot(ray.d, Quad::normal) == 0.0) 
        return Intersection::failure();
    
    float t = dot(center - ray.o, Quad::normal) / dot(ray.d, Quad::normal);
    if (t > tmax || t < tmin) 
        return Intersection::failure();
    
    Point strike__point = ray.getPoint(t);

    bool find1 = dot(cross(p2-p1, strike__point - p1), normal) >= 0;
    bool find2 = dot(cross(p3-p2, strike__point - p2), normal) >= 0;
    bool find3 = dot(cross(p4-p3, strike__point - p3), normal) >= 0;
    bool find4 = dot(cross(p1-p4, strike__point - p4), normal) >= 0;

    if (find1 && find2 && find3 && find4) {
        float u, v;
        Vector strike_v1 = strike__point - p1;

        if (fabs(span1.x * span2.y - span2.x * span1.y) >= epsilon) {
            u = (strike_v1.x * span2.y - span2.x * strike_v1.y) / (span1.x * span2.y - span2.x * span1.y);
            v = (span1.x * strike_v1.y - strike_v1.x * span1.y) / (span1.x * span2.y - span2.x * span1.y);
        }
        else if (fabs(span1.y * span2.z - span2.y * span1.z) >= epsilon) {
            u = (strike_v1.y * span2.z - span2.y * strike_v1.z) / (span1.y * span2.z - span2.y * span1.z);
            v = (span1.y * strike_v1.z - strike_v1.y * span1.z) / (span1.y * span2.z - span2.y * span1.z);
        }
        else {
            u = (strike_v1.z * span2.x - span2.z * strike_v1.x) / (span1.z * span2.x - span2.z * span1.x);
            v = (span1.z * strike_v1.x - strike_v1.z * span1.x) / (span1.z * span2.x - span2.z * span1.x);
        }
        
        return Intersection(t, ray, this, normal, Point(u, v, 0.0f));
    }
    else {
        return Intersection::failure();
    }

}

Solid::Sample Quad::sample() const {
    /* TODO */ NOT_IMPLEMENTED;
}

float Quad::getArea() const {
    // /* TODO */ NOT_IMPLEMENTED;
    Vector norm = cross(span1, span2);
    return norm.length();
}

}
