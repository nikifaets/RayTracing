#include "Matrix3D.h"
#include <iostream>
using namespace std;

Matrix3D::Matrix3D(){}
Matrix3D::Matrix3D(Vector3D x_, Vector3D y_, Vector3D z_): x(x_), y(y_), z(z_){

	matrix[0][0] = x.x;
	matrix[0][1] = x.y;
	matrix[0][2] = x.z;
	matrix[1][0] = y.x;
	matrix[1][1] = y.y;
	matrix[1][2] = y.z;
	matrix[2][0] = z.x;
	matrix[2][1] = z.y;
	matrix[2][2] = z.z;
}

void Matrix3D::update_vectors(){

	x = Vector3D(matrix[0][0], matrix[0][1], matrix[0][2]);
	y = Vector3D(matrix[1][0], matrix[1][1], matrix[1][2]);
	z = Vector3D(matrix[2][0], matrix[2][1], matrix[2][2]);
}

 void Matrix3D::operator = (const Matrix3D& arg ){

	for(int i=0; i<3; i++){

		for(int j=0; j<3; j++){

			this->matrix[i][j] = arg.matrix[i][j];
		}
	}

	update_vectors();

}

Matrix3D Matrix3D::operator * (const Matrix3D& M1){

	Matrix3D res(Vector3D(0,0,0), Vector3D(0,0,0), Vector3D(0,0,0));

	for(int i=0; i<3; i++){

		for(int j=0; j<3; j++){

			for(int k=0; k<3; k++){

				res.matrix[i][j] += matrix[i][k] * M1.matrix[k][j];
			}
		}
	}

	res.update_vectors();

	return res;
}

Vector3D Matrix3D::multiply_vector(const Vector3D& vec){


	Vector3D res(0,0,0);
	res.x = vec.x*matrix[0][0] + vec.y*matrix[1][0] + vec.z*matrix[2][0];
	res.y = vec.x*matrix[0][1] + vec.y*matrix[1][1] + vec.z*matrix[2][1];
	res.z = vec.x*matrix[0][2] + vec.y*matrix[1][2] + vec.z*matrix[2][2];

	return res;
}

void Matrix3D::print_matrix(){

	cout << " X " << x.x << " " << x.y << " " << x.z << endl;
	cout << " Y " << y.x << " " << y.y << " " << y.z << endl;
	cout << " Z " << z.x << " " << z.y << " " << z.z << endl;
}
