#ifndef LIGHT_H
#define LIGHT_H

#include "../Object3D.h"

class Light : public Object3D{

public:

	Light();

	Vector3D color;
	float intensity = 1;
};

#endif