#include "Vector3D.h"
#include <cmath>
#include <iostream>
using namespace std;

Vector3D::Vector3D(): x(0), y(0), z(0){}
Vector3D::Vector3D(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

float Vector3D::get_length(){

	return sqrt(x*x + y*y + z*z);
}

void Vector3D::operator = (const Vector3D& arg){

	this->x = arg.x;
	this->y = arg.y;
	this->z = arg.z;
}

Vector3D Vector3D::operator - (const Vector3D& arg){

	float x = this->x - arg.x;
	float y = this->y - arg.y;
	float z = this->z - arg.z;

	return Vector3D(x,y,z);
}

Vector3D Vector3D::operator + (const Vector3D& arg){

	float x = this->x + arg.x;
	float y = this->y + arg.y;
	float z = this->z + arg.z;

	return Vector3D(x,y,z);

}

Vector3D Vector3D::scale(const float arg){

	float x = this->x * arg;
	float y = this->y * arg;
	float z = this->z * arg;

	return Vector3D(x,y,z);
}

bool Vector3D::operator == (const Vector3D& arg){

	return this->x == arg.x && this->y == arg.x && this->z == arg.z;
}

bool Vector3D::operator != (const Vector3D& arg){

	return this->x != arg.x || this->y != arg.y || this->z != arg.z;
}

float Vector3D::dot(const Vector3D& arg){

	float dot_x = this->x * arg.x;
	float dot_y = this->y * arg.y;
	float dot_z = this->z * arg.z;

	return dot_x + dot_y + dot_z;
}

float Vector3D::distance_to(const Vector3D& arg){

	float dist_x = pow((this->x - arg.x), 2);
	float dist_y = pow((this->y - arg.y), 2);
	float dist_z = pow((this->z - arg.z), 2);

	return sqrt(dist_x + dist_y + dist_z);
}

void Vector3D::print_vector(){

	cout << "x " << x << " y " << y << " z " << z << endl;

}

void Vector3D::threshold(float min, float max){

	if(x < min) x = min;
	if(x > max) x = max;

	if(y < min) y = min;
	if(y > max) y = max;

	if(z < min) z = min;
	if(z > min) z = min;
}

Vector3D Vector3D::normalized(){

	float length = get_length();
	float xn = x/length;
	float yn = y/length;
	float zn = z/length;

	return Vector3D(xn, yn, zn);
}
