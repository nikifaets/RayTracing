#ifndef VECTOR_3D_H

#define VECTOR_3D_H

class Vector3D{

public:

	Vector3D();
	Vector3D(float x_, float y_, float z_);
	float x;
	float y;
	float z;

	void operator = (const Vector3D& arg);
};	

#endif