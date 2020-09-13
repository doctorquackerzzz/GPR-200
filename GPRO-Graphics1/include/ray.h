#ifndef RAY_H
#define RAY_H
/*
    include-ray.h
    ray class for more complex vector math.

    Modified by: Nico Omenetto
    Modified because: to functionalize the ray class into the program
*/
/*
Contains Code from the following source:
Chapter 4.1
Ray Tracing in One Weekend. https://raytracing.github.io/books/RayTracingInOneWeekend.html#rays,asimplecamera,andbackground/therayclass
Peter Shirley
Accessed 9 09. 2020.

*/
#include "gpro/gpro-math/gproVector.h"

//Intent: creation of the ray class
//reason: to initialize the class to incorporate into the program.
class ray {
public:
    //ray constructors
    ray() {}
    ray(const point3& origin, const vec3& direction)
        : orig(origin), dir(direction)
    {}

    // origin and direction functions
    point3 origin() const { return orig; }
    vec3 direction() const { return dir; }

    //Origin of ray + t(direction of ray)
    point3 at(float t) const {

        return orig + (dir * t); //origin + (direction * float t)
    }

    //public variables
    point3 orig;
    vec3 dir;
};

#endif