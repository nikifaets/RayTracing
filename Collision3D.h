#ifndef COLLISION_3D_H
#define COLLISION_3D_H

#include "Object3D.h"

struct Collision3D{

	Collision3D();
	Collision3D(Object3D *collider_, Vector3D collision_point_);
	Object3D* collider;
	Vector3D collision_point;

};

#endif