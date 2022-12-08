#include <core/homogeneouscoord.h>
#include <core/vector.h>
#include <core/point.h>
#include <core/assert.h>
#include <core/scalar.h>

namespace rt {

HomogeneousCoord::HomogeneousCoord(float x, float y, float z, float w) {
    /* TODO */
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

HomogeneousCoord::HomogeneousCoord(const Point& p) {
    /* TODO */ 
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    this->w = 1.f;
}

HomogeneousCoord::HomogeneousCoord(const Vector& vec) {
    /* TODO */ 
    this->x = vec.x;
    this->y = vec.y;
    this->z = vec.z;
    this->w = 0.f;
}

float& HomogeneousCoord::operator [] (int idx) {
    /* TODO */ 
    rt_assert(idx < 4);
    rt_assert(idx >= 0);
    switch (idx)
    {
      case 0: return x;
      case 1: return y;
      case 2: return z;
      case 3: return w;
      default: return 0;
    }

}

float HomogeneousCoord::operator [] (int idx) const {
    /* TODO */ 
    rt_assert(idx < 4);
    rt_assert(idx >= 0);
    switch (idx)
    {
      case 0: return x;
      case 1: return y;
      case 2: return z;
      case 3: return w;
      default: return 0;
    }
}

HomogeneousCoord HomogeneousCoord::operator + (const HomogeneousCoord& b) const {
    /* TODO */ 
    return HomogeneousCoord(this->x + b.x, this->y + b.y, this->z + b.z, this->w + b.w);
}

HomogeneousCoord HomogeneousCoord::operator - (const HomogeneousCoord& b) const {
    /* TODO */ 
    return HomogeneousCoord(this->x - b.x, this->y - b.y, this->z - b.z, this->w - b.w);
}

HomogeneousCoord HomogeneousCoord::operator * (const HomogeneousCoord& b) const {
    /* TODO */ 
    return HomogeneousCoord(this->x * b.x, this->y * b.y, this->z * b.z, this->w * b.w);
}

HomogeneousCoord HomogeneousCoord::operator / (const HomogeneousCoord& b) const {
    /* TODO */ 
    return HomogeneousCoord(this->x / b.x, this->y / b.y, this->z / b.z, this->w / b.w);
}

HomogeneousCoord operator * (float scalar, const HomogeneousCoord& b) {
    /* TODO */ 
    return HomogeneousCoord(scalar * b.x, scalar * b.y, scalar * b.z, scalar * b.w);
}

HomogeneousCoord operator * (const HomogeneousCoord& a, float scalar) {
    /* TODO */ 
    return HomogeneousCoord(a.x * scalar, a.y * scalar, a.z * scalar, a.w * scalar);
}

HomogeneousCoord operator / (const HomogeneousCoord& a, float scalar) {
    /* TODO */ 
    return HomogeneousCoord(a.x / scalar, a.y / scalar, a.z / scalar, a.w / scalar);

}

float dot(const HomogeneousCoord& a, const HomogeneousCoord& b) {
    /* TODO */ 
    return(a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

HomogeneousCoord HomogeneousCoord::operator - () const {
    /* TODO */ 
    return HomogeneousCoord(-x, -y, -z, -w);
}

bool HomogeneousCoord::operator == (const HomogeneousCoord& b) const {
    /* TODO */ 
    return ((this->x == b.x) && (this->y == b.y) && (this->z == b.z) && (this->w == b.w));

}

bool HomogeneousCoord::operator != (const HomogeneousCoord& b) const {
    /* TODO */ 
    return !((*this) == b);

}

HomogeneousCoord min(const HomogeneousCoord& a, const HomogeneousCoord& b) {
    /* TODO */ 
    return HomogeneousCoord(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w));
}

HomogeneousCoord max(const HomogeneousCoord& a, const HomogeneousCoord& b) {
    /* TODO */ 
    return HomogeneousCoord(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w));
}

}