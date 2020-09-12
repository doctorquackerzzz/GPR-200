#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
/*
    include-hittable_list.h
    hittable_list.h initialization and class + function creation

    Modified by: Nico Omenetto
    Modified because: to creat a list of hit objects as to allow the it to function in the main cpp file
*/
/*
Contains Code from the following source:

Ray Tracing in One Weekend. raytracing.github.io/books/RayTracingInOneWeekend.html
Peter Shirley
Accessed 9 09. 2020.

*/
#include "gpro/hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

//Intent: the class of the hittable list
//Reason: to keep track of the amount of hits on the sphere
class hittable_list : public hittable {
public:
    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    void clear() { objects.clear(); }
    void add(shared_ptr<hittable> object) { objects.push_back(object); }

    virtual bool hit(
        const ray& r, float tmin, float tmax, hit_record& rec) const override;

public:
    std::vector<shared_ptr<hittable>> objects;
};

//Intent: bool function of if it's considered a hit on the list
//reason: to determine whether attempts on the list hit the sphere
bool hittable_list::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    float closest_so_far = t_max;

    for (int i = 0; i < t_max; i++) {
        if (hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}

#endif