#include "Object3D.h"
#include "Vector3D.h"
class Sphere : public Object3D{

public:

	Sphere();
	Sphere(float radius_);
	Sphere(Vector3D center_, float radius_);
	
	float center = Vector3D(0,0,0);
	float radius = 1;
};