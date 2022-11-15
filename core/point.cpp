#include <core/point.h>
#include <core/homogeneouscoord.h>
#include <core/scalar.h>
#include <core/assert.h>
#include <core/vector.h>

namespace rt {

Point::Point(float x, float y, float z)
{
    /* TODO */
    Point::x = x;
    Point::y = y;
    Point::z = z;
}

Point::Point(const HomogeneousCoord& coord)
{
    /* TODO */ NOT_IMPLEMENTED;
}

Vector Point::operator - (const Point& b) const {
    /* TODO */ //NOT_IMPLEMENTED;
    float x_out = Point::x - b.x;
    float y_out = Point::y - b.y;
    float z_out = Point::z - b.z;
    return Vector(x_out, y_out, z_out);
}

bool Point::operator == (const Point& b) const {
    /* TODO */ //NOT_IMPLEMENTED;
    bool x_out = Point::x == b.x;
    bool y_out = Point::y == b.y;
    bool z_out = Point::z == b.z;
    return x_out && y_out && z_out;
}

bool Point::operator != (const Point& b) const {
    /* TODO */ //NOT_IMPLEMENTED;
    bool x_out = Point::x != b.x;
    bool y_out = Point::y != b.y;
    bool z_out = Point::z != b.z;
    return x_out || y_out || z_out;
}

Point operator * (float scalar, const Point& b) {
    /* TODO */ //NOT_IMPLEMENTED;
    float x_out = scalar * b.x;
    float y_out = scalar * b.y;
    float z_out = scalar * b.z;
    return Point(x_out, y_out, z_out);
}

Point operator * (const Point& a, float scalar) {
    /* TODO */ //NOT_IMPLEMENTED;
    float x_out = scalar * a.x;
    float y_out = scalar * a.y;
    float z_out = scalar * a.z;
    return Point(x_out, y_out, z_out);
}

Point min(const Point& a, const Point& b) {
    /* TODO */ //NOT_IMPLEMENTED;
    float x_out = min(a.x, b.x);
    float y_out = min(a.y, b.y);
    float z_out = min(a.z, b.z);
    return Point(x_out, y_out, z_out);
}

Point max(const Point& a, const Point& b) {
    /* TODO */ //NOT_IMPLEMENTED;
    float x_out = max(a.x, b.x);
    float y_out = max(a.y, b.y);
    float z_out = max(a.z, b.z);
    return Point(x_out, y_out, z_out);
}

}
