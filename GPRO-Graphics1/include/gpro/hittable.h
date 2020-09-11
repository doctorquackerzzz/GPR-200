#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

/*
    include-hittable.h
    hittable.h initialization and hit record + hittable creation

    Modified by: Nico Omenetto
    Modified because: to create the struct for the total hit record of the sphere and to create a class that will allow a function of whether or not the sphere was hit
*/
/*
Ray Tracing in One Weekend. raytracing.github.io/books/RayTracingInOneWeekend.html
Accessed 9 09. 2020.

*/
struct hit_record {
    vec3 p;
    vec3 normal;
    double t;
    bool front_face;

    inline void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
public:
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif