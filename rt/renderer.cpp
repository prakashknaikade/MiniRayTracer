#include <core/scalar.h>
#include <core/image.h>
#include <rt/renderer.h>
#include <rt/ray.h>
#include <iostream>

namespace rt {

Renderer::Renderer(Camera* cam, Integrator* integrator)
    : cam(cam), integrator(integrator), samples(1)
{}

void Renderer::render(Image& img) {
    CG_UNUSED(img);
    /* TODO */ NOT_IMPLEMENTED;
}

}

rt::RGBColor a1computeColor(rt::uint x, rt::uint y, rt::uint width, rt::uint height);

namespace rt {

void Renderer::test_render1(Image& img) {
    //CG_UNUSED(img);
    /* TODO */ //NOT_IMPLEMENTED;
    uint width = img.width();
    uint height = img.height();

    for (uint i = 0; i < width; i++) {
        for (uint j = 0; j < height; j++) {
            img(i, j) = a1computeColor(i, j, width, height);
        }
    }
}
}

rt::RGBColor a2computeColor(const rt::Ray& r);

namespace rt {

void Renderer::test_render2(Image& img) {
    CG_UNUSED(img);
    /* TODO */ NOT_IMPLEMENTED;
}

}
