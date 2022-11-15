#include <core/color.h>
#include <core/scalar.h>
#include <core/homogeneouscoord.h>

namespace rt {

RGBColor::RGBColor(const HomogeneousCoord& coord)
{
    /* TODO */ NOT_IMPLEMENTED;
}

RGBColor RGBColor::operator + (const RGBColor& c) const {
    /* TODO */ //NOT_IMPLEMENTED;
    float r_out = RGBColor::r + c.r;
    float g_out = RGBColor::g + c.g;
    float b_out = RGBColor::b + c.b;
    return RGBColor(r_out, g_out, b_out);
}

RGBColor RGBColor::operator - (const RGBColor& c) const {
    /* TODO */ //NOT_IMPLEMENTED;
    float r_out = RGBColor::r - c.r;
    float g_out = RGBColor::g - c.g;
    float b_out = RGBColor::b - c.b;
    return RGBColor(r_out, g_out, b_out);
}

RGBColor RGBColor::operator * (const RGBColor& c) const {
    /* TODO */ //NOT_IMPLEMENTED;
    float r_out = RGBColor::r * c.r;
    float g_out = RGBColor::g * c.g;
    float b_out = RGBColor::b * c.b;
    return RGBColor(r_out, g_out, b_out);
}

bool RGBColor::operator == (const RGBColor& c) const {
    /* TODO */ //NOT_IMPLEMENTED;
    bool r_out = RGBColor::r == c.r;
    bool g_out = RGBColor::g == c.g;
    bool b_out = RGBColor::b == c.b;
    return r_out && g_out && b_out;
}

bool RGBColor::operator != (const RGBColor& b) const {
    /* TODO */ //NOT_IMPLEMENTED;
    bool r_out = RGBColor::r != b.r;
    bool g_out = RGBColor::g != b.g;
    bool b_out = RGBColor::b != b.b;
    return r_out || g_out || b_out;
}

RGBColor RGBColor::clamp() const {
    /* TODO */ //NOT_IMPLEMENTED;
    float r_out = 0, g_out = 0, b_out = 0;
    if (RGBColor::r < 0){
        r_out = 0;
    }
    else if (RGBColor::r > 1){
        r_out = 1;
    }
    else{
        r_out = RGBColor::r;
    }
    
    if (RGBColor::g < 0){
        g_out = 0;
    }
    else if (RGBColor::g > 1){
        g_out = 1;
    }
    else{
        g_out = RGBColor::g;
    }

    if (RGBColor::b < 0){
        b_out = 0;
    }
    else if (RGBColor::b > 1){
        b_out = 1;
    }
    else{
        b_out = RGBColor::b;
    }

    return RGBColor(r_out, g_out, b_out);
}

RGBColor RGBColor::gamma(float gam) const {
    /* TODO */ NOT_IMPLEMENTED;
}

float RGBColor::luminance() const {
    /* TODO */ NOT_IMPLEMENTED;
}

RGBColor operator * (float scalar, const RGBColor& c) {
    /* TODO */ //NOT_IMPLEMENTED;
    float r_out = scalar * c.r;
    float g_out = scalar * c.g;
    float b_out = scalar * c.b;
    return RGBColor(r_out, g_out, b_out);
}

RGBColor operator * (const RGBColor& c, float scalar) {
    /* TODO */ //NOT_IMPLEMENTED;
    float r_out = scalar * c.r;
    float g_out = scalar * c.g;
    float b_out = scalar * c.b;
    return RGBColor(r_out, g_out, b_out);
}

RGBColor operator / (const RGBColor& c, float scalar) {
    /* TODO */ //NOT_IMPLEMENTED;
    float r_out = c.r / scalar;
    float g_out = c.g / scalar;
    float b_out = c.b / scalar;
    return RGBColor(r_out, g_out, b_out);
}

}
