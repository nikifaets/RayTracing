#ifndef SPHERE_H
#define SPHERE_H

#include "Object3D.h"
#include "Vector3D.h"
#include "Collision3D.h"

class Sphere : public Object3D{

public:

	float radius = 1;
	
	Sphere();
	Sphere(float radius_);
	Sphere(Vector3D center_, float radius_);
	Vector3D intersects_ray(Vector3D& from, Vector3D& to);

};

#endif