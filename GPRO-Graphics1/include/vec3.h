#ifndef VEC3_H
#define VEC3_H
/*
    include-vec3.h
    vec3.h inclusion and operator fixing between gproVector and vec3.h

    Modified by: Nico Omenetto
    Modified because: to troubleshoot the operator overloading, and make the function flow
*/
/*
Ray Tracing in One Weekend. raytracing.github.io/books/RayTracingInOneWeekend.html
Accessed 9 09. 2020.

*/
#include <cmath>
#include <iostream>

using std::sqrt;

//Purpose: To create a class for vec3 that can work inside the other header files and the main cpp file
//Reason: Even though it's already declared, this is for troubleshooting the operator overloading
class vec3 {
public:
    vec3() : e{ 0,0,0 } {}
    vec3(double e0, double e1, double e2) : e{ e0, e1, e2 } {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }
    
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vec3& operator*=(const double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3& operator/=(const double t) {
        return *this *= 1 / t;
    }

    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

public:
    double e[3];
};

// Type aliases for vec3
using point3 = vec3;   // 3D point
using color = vec3;    // RGB color

// vec3 Utility Functions
//Purpose: Operator overloading for vec3
//Reason: Troubleshooting purposes, because this doesn't work without the vec3.h file, but in the technical term
// this basically calculates the different equations for the vectors.
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

//additive operator overload
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}
//subtractive operator overload
inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}
 //multiplicative operator overload one with two vectors
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

//multiplicative operator overloading between vector and double
inline vec3 operator*(double t, const vec3& v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

//simplistic verstion of the the previous operator overloading, since the order of what goes first is flipped
inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

//divisibilitative operator overloading
inline vec3 operator/(vec3 v, double t) {
    return (1 / t) * v;
}

//dot product function
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2];
}
//cross product function
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

//unitvector function
inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

#endif