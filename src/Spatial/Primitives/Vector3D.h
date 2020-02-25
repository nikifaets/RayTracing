#ifndef VECTOR_3D_H

#define VECTOR_3D_H

#include <cmath>

#define null_vector Vector3D(INFINITY, INFINITY, INFINITY)

class Vector3D{

public:

	float x;
	float y;
	float z;

	Vector3D();
	Vector3D(float val);
	Vector3D(float x_, float y_, float z_);

	float get_length();

	void operator = (const Vector3D& arg);

	Vector3D operator - (const Vector3D& arg);

	Vector3D operator + (const Vector3D& arg);
	
	Vector3D scale (const float arg);

	bool operator == (const Vector3D& arg);

	bool operator != (const Vector3D& arg);
	
	float dot(const Vector3D& arg);

	float distance_to(const Vector3D& arg);

	void print_vector();

	void threshold(float min, float max);

	Vector3D normalized();
};	


#endif