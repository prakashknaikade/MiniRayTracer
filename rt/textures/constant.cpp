#include <rt/textures/constant.h>

namespace rt {

ConstantTexture::ConstantTexture()
{
    /* TODO */
}

ConstantTexture::ConstantTexture(const RGBColor& color)
{
    // CG_UNUSED(color);
    /* TODO */
     this->const_color = color;
}

RGBColor ConstantTexture::getColor(const Point& coord) {
    CG_UNUSED(coord);
    // /* TODO */ NOT_IMPLEMENTED;
    return const_color;
}

RGBColor ConstantTexture::getColorDX(const Point& coord) {
    CG_UNUSED(coord);
    // /* TODO */ NOT_IMPLEMENTED;
    return RGBColor::rep(0.0f);
}

RGBColor ConstantTexture::getColorDY(const Point& coord) {
    CG_UNUSED(coord);
    // /* TODO */ NOT_IMPLEMENTED;
    return RGBColor::rep(0.0f);
}

}