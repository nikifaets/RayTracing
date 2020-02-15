#ifndef OBJECT_3D_H
#define OBJECT_3D_H

#include <string>
#include "Matrix3D.h"
#include "Vector3D.h"

class Object3D{

public:

	Object3D();
	std::string obj_type = "Undefined";

	bool intersects_ray(float direction);
	void set_type(std::string new_type);
	Matrix3D basis;
};
#endif