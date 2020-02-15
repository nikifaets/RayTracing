#include "Vector3D.h"

Vector3D::Vector3D(){}
Vector3D::Vector3D(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

void Vector3D::operator = (const Vector3D& arg){

	this->x = arg.x;
	this->y = arg.y;
	this->z = arg.z;
}