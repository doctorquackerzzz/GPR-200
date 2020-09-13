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
Chapter 6.3
Ray Tracing in One Weekend. https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/anabstractionforhittableobjects
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
    //boolean function of hit
    virtual bool hit(
        const ray& r, float tmin, float tmax, hit_record& rec) const override;

    //public variables
    point3 center;
    float radius = 30.0f; // initialized radius
};

//intent: to determine whether or not the sphere has been hit
//reason: to provide a sense as to what the equations are to calculate whther the sphere was hit
bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
    point3 oc = r.origin() - center; //ray point of origin minus center = oc
    float a = r.direction().length_squared(); //vector of direction length squared
    float half_b = dot(oc, r.direction()); // dot product of oc and the direction of ray
    float c = oc.length_squared() - radius * radius; // length squared of oc vector - radius times radius
    float discriminant = half_b * half_b - a * c; // half of b * half of b - a times c

    //if statement to determine whether the sphere was hit or not
    if (discriminant > 0) {
        float root = sqrt(discriminant);

        float temp = (-half_b - root) / a;
        if (temp < t_max && temp > t_min) {  //if temporary value was less than max and greater than min for -halfb - root/a
            rec.t = temp;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }

        temp = (-half_b + root) / a;
        if (temp < t_max && temp > t_min) { //if temporary value is less than max or greater than min 
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