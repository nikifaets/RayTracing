#include "Sphere.h"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

const float eps = 1e-6;

Sphere::Sphere() : radius(1){

	translation = Vector3D(0,0,0);
	obj_type = "Sphere";
}

Sphere::Sphere(float radius_) : radius(radius_){

	translation = Vector3D(0,0,0);
	obj_type = "Sphere";
}

Sphere::Sphere(Vector3D center_, float radius_) : radius(radius_){

	translation = center_;
	obj_type = "Sphere";
}

Vector3D Sphere::intersects_ray(Vector3D& from, Vector3D& to){

	//equation: t^2 * (d*d) + t * 2(from*d - center*d) + center*center - from*center + from*from - raduis^2 = 0  

	if( from == to) return null_vector;
	if(translation == from) return null_vector;

	Vector3D ray_direction = (to - from).normalized();

	float a = ray_direction.dot(ray_direction);
	float b = 2 * (from.dot(ray_direction) - translation.dot(ray_direction));
	float c = translation.dot(translation) + from.dot(from) - translation.dot(from) - radius*radius;

	//cout << "a " << a << " b " << b << " c " << c << endl;
	float D = sqrt(b*b - 4*a*c);

	float t1 = (-b + D) / 2*a;
	float t2 = (-b - D) / 2*a;

	if(t1 < 0 && t2 < 0 ) return null_vector;

	if(abs(t1 - t2) < eps) {

		Vector3D intersection_point = from + ray_direction.scale(t1);
		//cout << "intersection t1 == t2" << endl;
		//intersection_point.print_vector();
		return intersection_point;
	}

	Vector3D intersection1 = from + ray_direction.scale(t1);
	Vector3D intersection2 = from + ray_direction.scale(t2);

	float dist1 = intersection1.distance_to(from);
	float dist2 = intersection2.distance_to(from);

	if(dist1 < dist2 && t1 > -eps) return intersection1;

	else if(t2 > -eps) return intersection2;

	return null_vector;
	


}
