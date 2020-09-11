#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
/*
    include-rtweekend.h
    rtweekend.h initialization and shortcuts backdrop

    Modified by: Nico Omenetto
    Modified because: to create shortcuts for stds and common headers within the main cpp file
*/
/*
Ray Tracing in One Weekend. raytracing.github.io/books/RayTracingInOneWeekend.html
Accessed 9 09. 2020.

*/

// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// Common Headers

#include "ray.h"
#include "gpro/gpro-math/gproVector.h"
#include "gpro/vec3.h"
#endif