#include <core/scalar.h>
#include <core/vector.h>
#include <core/point.h>
#include <core/homogeneouscoord.h>
#include <core/assert.h>
#include <algorithm>
#include <cmath>

namespace rt {

Vector::Vector(float x, float y, float z)
{
    /* TODO */
    Vector::x = x;
    Vector::y = y;
    Vector::z = z;
}

Vector::Vector(const HomogeneousCoord& coord)
{
    /* TODO */ NOT_IMPLEMENTED;
    // Vector::x = coord.x / coord.w;
    // Vector::y = coord.y / coord.w;
    // Vector::z = coord.z / coord.w;
}

Vector Vector::operator + (const Vector& b) const {
    /* TODO */ // NOT_IMPLEMENTED;
    float x_out = Vector::x + b.x;
    float y_out = Vector::y + b.y;
    float z_out = Vector::z + b.z;
    return Vector(x_out, y_out, z_out);
}

Vector Vector::operator - (const Vector& b) const {
    /* TODO */ //NOT_IMPLEMENTED;
    float x_out = Vector::x - b.x;
    float y_out = Vector::y - b.y;
    float z_out = Vector::z - b.z;
    return Vector(x_out, y_out, z_out);
}

Vector Vector::operator - () const {
    /* TODO */ NOT_IMPLEMENTED;
}

Vector Vector::normalize() const {
    /* TODO */ //NOT_IMPLEMENTED;
    float norm = Vector::length();
    float x_out = Vector::x / norm;
    float y_out = Vector::y / norm;
    float z_out = Vector::z / norm;
    return Vector(x_out, y_out, z_out);
}

Vector operator * (float scalar, const Vector& b) {
    /* TODO */ //NOT_IMPLEMENTED;
    float x_out = scalar * b.x;
    float y_out = scalar * b.y;
    float z_out = scalar * b.z;
    return Vector(x_out, y_out, z_out);
}

Vector operator * (const Vector& a, float scalar) {
    /* TODO */ //NOT_IMPLEMENTED;
    float x_out = scalar * a.x;
    float y_out = scalar * a.y;
    float z_out = scalar * a.z;
    return Vector(x_out, y_out, z_out);
}

Vector operator / (const Vector& a, float scalar) {
    /* TODO */ //NOT_IMPLEMENTED;
    float x_out = a.x / scalar;
    float y_out = a.y / scalar;
    float z_out = a.z / scalar;
    return Vector(x_out, y_out, z_out);
}

Vector cross(const Vector& a, const Vector& b) {
    /* TODO */ NOT_IMPLEMENTED;
    float x_out = a.y*b.z - a.z*b.y;
    float y_out = a.x*b.z - a.z*b.x;
    float z_out = a.x*b.y - a.y*b.z;
    return Vector(x_out, y_out, z_out);
}

float dot(const Vector& a, const Vector& b) {
    /* TODO */ //NOT_IMPLEMENTED;
    float out = a.x*b.x + a.y*b.y + a.z*b.z;
    return out;
}

float Vector::lensqr() const {
    /* TODO */ //NOT_IMPLEMENTED;
    float a = Vector::length();
    return sqr(a);
}

float Vector::length() const {
    /* TODO */ //NOT_IMPLEMENTED;
    return sqrt(pow(Vector::x, 2) + pow(Vector::y, 2) + pow(Vector::z, 2));
}


bool Vector::operator == (const Vector& b) const {
    /* TODO */ //NOT_IMPLEMENTED;
    bool x_out = Vector::x == b.x;
    bool y_out = Vector::y == b.y;
    bool z_out = Vector::z == b.z;
    return x_out && y_out && z_out;
}

bool Vector::operator != (const Vector& b) const {
    /* TODO */ //NOT_IMPLEMENTED;
    bool x_out = Vector::x != b.x;
    bool y_out = Vector::y != b.y;
    bool z_out = Vector::z != b.z;
    return x_out || y_out || z_out;
}

Vector min(const Vector& a, const Vector& b) {
    /* TODO */ //NOT_IMPLEMENTED;
    float x_out = min(a.x, b.x);
    float y_out = min(a.y, b.y);
    float z_out = min(a.z, b.z);
    return Vector(x_out, y_out, z_out);
}

Vector max(const Vector& a, const Vector& b) {
    /* TODO */ //NOT_IMPLEMENTED;
    float x_out = max(a.x, b.x);
    float y_out = max(a.y, b.y);
    float z_out = max(a.z, b.z);
    return Vector(x_out, y_out, z_out);
}

Point operator + (const Point& a, const Vector& b) {
    /* TODO */ //NOT_IMPLEMENTED;
    float x_out = a.x + b.x;
    float y_out = a.y + b.y;
    float z_out = a.z + b.z;
    return Point(x_out, y_out, z_out);
}

Point operator + (const Vector& a, const Point& b) {
    /* TODO */ //NOT_IMPLEMENTED;
    float x_out = a.x + b.x;
    float y_out = a.y + b.y;
    float z_out = a.z + b.z;
    return Point(x_out, y_out, z_out);
}

Point operator - (const Point& a, const Vector& b) {
    /* TODO */ //NOT_IMPLEMENTED;
    float x_out = a.x - b.x;
    float y_out = a.y - b.y;
    float z_out = a.z - b.z;
    return Point(x_out, y_out, z_out);
}

Point operator * (const HomogeneousCoord& scale, const Point& p) {
    /* TODO */ //NOT_IMPLEMENTED;
}

}
