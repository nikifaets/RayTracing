#ifndef OBJECT_3D_H
#define OBJECT_3D_H


#include <string>

class Object3D{

public:

	std::string obj_type = "Undefined";

	bool intersects_ray(float direction);
	void set_type(std::string new_type);

	float basis;
};

#endif