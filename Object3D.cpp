#include "Object3D.h"
#include <iostream>
#include <cmath> 

void Object3D :: set_type(std::string new_type){

	obj_type = new_type;
}

Object3D::Object3D(){

	basis = Matrix3D(Vector3D(1,0,0), Vector3D(0,1,0), Vector3D(0,0,1));
	translation = Vector3D(0,0,0);
	color = Vector3D(0,0,0);
}

Vector3D Object3D::intersects_ray(Vector3D& from, Vector3D& to){

	return null_vector;
}

void Object3D::rotate_z(float angle){

	Matrix3D rotation_matrix(
		Vector3D(cos(angle), -sin(angle), 0),
		Vector3D(sin(angle), cos(angle), 0),
		Vector3D(0, 0, 1));


	basis = basis * rotation_matrix;
}