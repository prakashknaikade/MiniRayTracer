#include <rt/integrators/castingdist.h>
#include <core/vector.h>
#include <rt/intersection.h>
#include <rt/world.h>
#include <rt/solids/solid.h>


namespace rt {

RayCastingDistIntegrator::RayCastingDistIntegrator(World* world, const RGBColor& nearColor, float nearDist, const RGBColor& farColor, float farDist)
    : Integrator(world), nearColor(nearColor), nearDist(nearDist), farColor(farColor), farDist(farDist)
{
    /* TODO */
}

RGBColor RayCastingDistIntegrator::getRadiance(const Ray& ray) const {
    /* TODO */ //NOT_IMPLEMENTED;
    Intersection intersec = world->scene->intersect(ray);

    if (intersec)
    {
        float weight;
        if (intersec.distance < nearDist)
            weight = 1.0f;
        else if (intersec.distance > farDist)
            weight = 0.0f;
        else
            weight = (farDist - intersec.distance) / (farDist - nearDist);

        float cos = abs(dot(intersec.normal().normalize(), ray.d.normalize()));

        cos = max(cos, 0.0f);
        const RGBColor color = nearColor * weight + farColor * (1.0f - weight);

        return color; //* cos;
    }
    else {
        return RGBColor(0, 0, 0);
    }
}

}
