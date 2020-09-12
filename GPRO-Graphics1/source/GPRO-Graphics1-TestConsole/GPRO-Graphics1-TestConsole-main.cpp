/*
   Copyright 2020 Daniel S. Buckstein

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

/*
	GPRO-Graphics1-TestConsole-main.c/.cpp
	Main entry point source file for a Windows console application.

	Modified by: Nico Omenetto
	Modified because: The starting point for the assignment as well as the creation of the ppm file within the main function
*/
/*
Contains Code from the following source:

Ray Tracing in One Weekend. raytracing.github.io/books/RayTracingInOneWeekend.html
Peter Shirley
Accessed 9 09. 2020.

*/

#include <stdio.h>
#include <stdlib.h>


#include "gpro/gpro-math/gproVector.h"
#include "gpro/rtweekend.h"
#include "gpro/hittable_list.h"
#include "gpro/color.h"
#include "gpro/sphere.h"


//Intent: to calculato whether the sphere has been hit
//Reason: for if the sphere is hit, it will calculate where it can be
double hit_sphere(const vec3& center, float radius, const ray& r) {
	vec3 oc = r.origin() - center;
	float a = r.direction().length_squared();
	float half_b = dot(oc, r.direction());
	float c = oc.length_squared() - radius * radius;
	float discriminant = half_b * half_b - 4 * a * c;
	//if the sphere was hit or not, the calculation of the place from the origin is calculated
	if (discriminant < 0) {
		return -1.0;
	}
	else {
		return -half_b - sqrt(discriminant) / (2.0 * a);
	}
}

//Intent: To create the ray color
//Reason: as hit, it will determine what specific color got hit and make the ray that color
vec3 ray_color(const ray& r, const hittable& world) {
	hit_record rec;
	//the if to create the color of the hit ray.
	if (world.hit(r, 0, infinity, rec)) {
		return (rec.normal + color(1, 1, 1)) * 0.5f;
	}
	vec3 unit_direction = unit_vector(r.direction());
	float t = (unit_direction.y + 1.0f) * 0.5f;
	return (color(1.0f, 1.0f, 1.0f) * (1.0f - t) + (color(0.5f, 0.7f, 1.0f) * t));
}

void testVector()
{
	// test array vector initializers and functions
	float3 av, bv, cv, dv;
	vec3default(av);								// -> a = (0, 0, 0)
	vec3init(bv, 1.0f, 2.0f, 3.0f);					// -> b = (1, 2, 3)
	vec3copy(dv, vec3init(cv, 4.0f, 5.0f, 6.0f));	// -> d = c = (4, 5, 6)
	vec3copy(av, dv);								// a = d			-> a = (4, 5, 6)
	vec3add(dv, bv);								// d += b			-> d = (4 + 1, 5 + 2, 6 + 3) = (5, 7, 9)
	vec3sum(dv, bv, bv);							// d = b + b		-> d = (1 + 1, 2 + 2, 3 + 3) = (2, 4, 6)
	vec3add(vec3sum(dv, cv, bv), av);				// d = c + b + a	-> d = (4 + 1 + 4, 5 + 2 + 5, 6 + 3 + 6) = (9, 12, 15)

#ifdef __cplusplus
	// test all constructors and operators
	vec3 a, b(1.0f, 2.0f, 3.0f), c(cv), d(c);		// default; init; copy array; copy
	a = d;											// assign						-> a = (4, 5, 6)
	d += b;											// add assign					-> d = (5, 7, 9)
	d = b + b;										// sum, init, assign			-> d = (2, 4, 6)
	d = c + b + a;									// sum, init, sum, init, assign	-> d = (9, 12, 15)
#endif	// __cplusplus
}





int main(int const argc, char const* const argv[])
{
	testVector();
	

	// Image
	const float aspect_ratio = 16.0f / 9.0f; //aspect ratio
	const int image_width = 400;// image's width
	const int image_height = static_cast<int>(image_width / aspect_ratio); //images height

	// World
	hittable_list world;
	world.add(make_shared<sphere>(point3(0, 0, -1), 0.5f));			\
	world.add(make_shared<sphere>(point3(0, -100.5, -1), 100.0f));

	// Camera

	float viewport_height = 2.0; //viewport height
	float viewport_width = aspect_ratio * viewport_height; //viewport width
	float focal_length = 1.0;//focal length

	point3 origin = point3(0, 0, 0); //origin
	vec3 horizontal = vec3(viewport_width, 0, 0); //horizontal
	vec3 vertical = vec3(0, viewport_height, 0); //vertical
	point3 lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);//lower left corner of ppm
	// Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";


	//compilation of the ppm file through the color builder
	for (int j = image_height - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i) {
			float u = float(i) / (image_width - 1);
			float v = float(j) / (image_height - 1);
			ray r(origin, lower_left_corner + (horizontal * u) + (vertical * v));
			color pixel_color = ray_color(r, world);
			write_color(std::cout, pixel_color);

		}
	}
	std::cerr << "\nDone.\n";
	
	
	printf("\n\n");
	system("pause");
	
}
