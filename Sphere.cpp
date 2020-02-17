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

	//ray: from + t*direction; t = - (from * direction - center*direction) / direction^2 

	if( from == to) return null_vector;
	if(translation == from) return null_vector;

	Vector3D ray_direction = to - from;

	float numerator = from.dot(ray_direction) - translation.dot(ray_direction);
	float denominator = ray_direction.dot(ray_direction);

	float t = -numerator / denominator;

	Vector3D intersection_point = from + ray_direction.scale(t);

	float dist = translation.distance_to(intersection_point);


	if(dist < radius && t > 0){

		return intersection_point;
	}

	return  null_vector;


}
