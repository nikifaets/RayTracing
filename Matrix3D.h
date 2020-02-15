#ifndef MATRIX_3D_H
#define MATRIX_3D_H

#include <vector>
#include "Vector3D.h"

class Matrix3D{

public:

	Vector3D x;
	Vector3D y;
	Vector3D z;
	Matrix3D();
	Matrix3D(Vector3D x_, Vector3D y_, Vector3D z_);
	void set_matrix(int matrix_[3][3]);
	void operator = (const Matrix3D &arg);


private:

	int rows;
	int cols;
	float matrix[3][3];

};

#endif