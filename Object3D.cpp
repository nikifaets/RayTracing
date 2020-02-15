#include "Object3D.h"
#include <iostream>
void Object3D :: set_type(std::string new_type){

	obj_type = new_type;
}

Object3D::Object3D(){

	basis = Matrix3D(Vector3D(1,0,0), Vector3D(0,1,0), Vector3D(0,0,1));
	translation = Vector3D(0,0,0);
	color = Vector3D(0,0,0);
}

bool Object3D::intersects_ray(Vector3D& from, Vector3D& to){

	return false;
}