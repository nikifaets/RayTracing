#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include "../Light.h"

class DirectionalLight: public Light{

public:

	DirectionalLight();
	DirectionalLight(Vector3D direction_);
	Vector3D direction;
};

#endif