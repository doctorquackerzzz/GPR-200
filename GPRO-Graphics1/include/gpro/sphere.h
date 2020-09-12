#ifndef SPHERE_H
#define SPHERE_H
/*
    include-sphere.h
    sphere class and bool function initialization

    Modified by: Nico Omenetto
    Modified because: to manipulate and to functionalize the sphere.h file into the program
*/
/*
Contains Code from the following source:

Ray Tracing in One Weekend. raytracing.github.io/books/RayTracingInOneWeekend.html
Peter Shirley
Accessed 9 09. 2020.

*/
#include "hittable.h"
#include "gpro/gpro-math/gproVector.h"


//Intent: creation of the sphere class
//Reason: to create a sphere class to display in the ppm file
class sphere : public hittable {
public:
    sphere() {}
    sphere(point3 cen, float r) : center(cen), radius(r) {};
    virtual bool hit(
        const ray& r, float tmin, float tmax, hit_record& rec) const override;

    point3 center;
    float radius;
};

//intent: to determine whether or not the sphere has been hit
//reason: to provide a sense as to what the equations are to calculate whther the sphere was hit
bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
    vec3 oc = r.origin() - center;
    float a = r.direction().length_squared();
    float half_b = dot(oc, r.direction());
    float c = oc.length_squared() - radius * radius;
    float discriminant = half_b * half_b - a * c;

    if (discriminant > 0) {
        float root = sqrt(discriminant);

        float temp = (-half_b - root) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }

        temp = (-half_b + root) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }
    }

    return false;
}


#endif