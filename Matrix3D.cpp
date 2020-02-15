#include "Matrix3D.h"


Matrix3D::Matrix3D(){}
Matrix3D::Matrix3D(Vector3D x_, Vector3D y_, Vector3D z_): x(x_), y(y_), z(z_){}

 void Matrix3D::operator = (const Matrix3D& arg ){

	for(int i=0; i<3; i++){

		for(int j=0; j<3; j++){

			this->matrix[i][j] = arg.matrix[i][j];
		}
	}
}