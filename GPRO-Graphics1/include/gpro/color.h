#ifndef COLOR_H
#define COLOR_H

#include "ray.h"
#include "gpro-math/gproVector.h"
/*
    include-color.h
    color.h initialization and the writecolor function

    Modified by: Nico Omenetto
    Modified because: to manipulate the program as to allow the writing of color to the ppm file
*/
/*
Contains Code from the following source:

Chapter 3.3
Ray Tracing in One Weekend. https://raytracing.github.io/books/RayTracingInOneWeekend.html#thevec3class/colorutilityfunctions
Peter Shirley
Accessed 9 09. 2020.

*/

#include <iostream>
//Intent: To display the color of the ppm file
//Reason: The function can be able to write out what it needs to for color
void write_color(std::ostream& out, vec3 pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x) << ' ' //R
        << static_cast<int>(255.999 * pixel_color.y) << ' ' //B
        << static_cast<int>(255.999 * pixel_color.z) << '\n'; //G
}




#endif