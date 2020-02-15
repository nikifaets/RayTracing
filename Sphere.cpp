#include "Sphere.h"
#include <string>
Sphere::Sphere() : radius(1), center(Vector3D(0,0,0)){

	obj_type = "Sphere";
}

Sphere::Sphere(float radius_) : radius(radius_), center(Vector3D(0,0,0)){

	obj_type = "Sphere";
}

Sphere::Sphere(Vector3D center_, float radius_) : center(center_), radius(radius_){

	obj_type = "Sphere";
}

bool Sphere::ray_intersects(Vector3D from, Vector3D to){

	//ray: from + t*direction; t = - (from * direction - center*direction) / direction^2 

	if( from == to) return false;
	if(center == from) return false;

	Vector3D ray_direction = to - from;

	float numerator = from.dot(ray_direction) - center.dot(ray_direction);
	float denominator = ray_direction.dot(ray_direction);

	float t = numerator / denominator;

	Vector3D intersection_point = from + to.scale(t);

	float dist = center.distance_to(intersection_point);

	return dist < radius;
}