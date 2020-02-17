#ifndef OBJECT_3D_H
#define OBJECT_3D_H

#include <string>
#include "Matrix3D.h"
#include "Vector3D.h"

class Object3D{

public:

	Vector3D translation;
	Matrix3D basis;
	std::string obj_type = "Undefined";
	Vector3D color;

	Object3D();

	virtual Vector3D intersects_ray(Vector3D& from, Vector3D& to);
	void set_type(std::string new_type);
	void rotate_z(float angle);

};

#endif