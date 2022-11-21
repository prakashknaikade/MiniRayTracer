#include <rt/solids/sphere.h>

namespace rt {

Sphere::Sphere(const Point& center, float radius, CoordMapper* texMapper, Material* material)
{
    /* TODO */
    Sphere::center = center;
	Sphere::radius = radius;
}

BBox Sphere::getBounds() const {
    /* TODO */ NOT_IMPLEMENTED;
}

Intersection Sphere::intersect(const Ray& ray, float tmin, float tmax) const {
    /* TODO */ //NOT_IMPLEMENTED;
    float L = dot(ray.d, ray.d);
    float M = 2.0f * dot(ray.o - center, ray.d);
    float N = dot(ray.o - center, ray.o - center) - (radius * radius);
    
    float t, d = M * M - 4 * L * N;
    
    Vector normal;

	if (d < 0.0f) 
        return Intersection::failure();
    else {
        float t1 = (- M + sqrt(d)) / (2 * A);
        float t2 = (- M - sqrt(d)) / (2 * A);

        bool is_t1_valid = is_t_valid(t1, previousBestDistance);
        bool is_t2_valid = is_t_valid(t2, previousBestDistance);

        if (!is_t1_valid && !is_t2_valid) 
            return Intersection::failure();
        if (is_t1_valid && is_t2_valid) t = min(t1, t2);
        if (!is_t1_valid && is_t2_valid) t = t2;
        if (is_t1_valid && !is_t2_valid) t = t1;
		}

    normal = ray.getPoint(t) - center;
    Point hit_Point = ray.getPoint(t);
    return(Intersection(t - epsilon, ray, this, normal.normalize(), hit_Point));
}

Solid::Sample Sphere::sample() const {
	NOT_IMPLEMENTED;
}

float Sphere::getArea() const {
    /* TODO */ //NOT_IMPLEMENTED;
    return (4*pi*pow(radius, 2));
}

}
