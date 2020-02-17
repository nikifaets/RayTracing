#ifndef MATRIX_3D_H
#define MATRIX_3D_H

#include <vector>
#include "Vector3D.h"

class Matrix3D{

public:

	Vector3D x;
	Vector3D y;
	Vector3D z;
	float matrix[3][3];

	Matrix3D();
	Matrix3D(Vector3D x_, Vector3D y_, Vector3D z_);
	void set_matrix(int matrix_[3][3]);
	void operator = (const Matrix3D& arg);
	Matrix3D operator * (const Matrix3D& M1);
	Vector3D multiply_vector(const Vector3D& vec);
	void update_vectors();
	void print_matrix();


};

#endif