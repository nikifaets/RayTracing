#include "Object3D.h"
#include "Vector3D.h"
class Sphere : public Object3D{

public:

	Vector3D center;
	float radius = 1;
	
	Sphere();
	Sphere(float radius_);
	Sphere(Vector3D center_, float radius_);
	bool ray_intersects(Vector3D from, Vector3D to);

};