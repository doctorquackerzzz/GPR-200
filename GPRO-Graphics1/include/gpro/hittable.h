#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
/*
    include-hittable.h
    color.h initialization and the writecolor function

    Modified by: Nico Omenetto
    Modified because: to manipulate the program as to allow the writing of color to the ppm file
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