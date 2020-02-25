#ifndef RAY_H
#define RAY_H

#include <vector>
#include "../Collision/Collision3D.h"
#include "../Object3D/Object3D.h"

class Ray{

public:
	Ray();
	Ray(Vector3D from_, Vector3D to_);
	
	Vector3D from;
	Vector3D to;
	std::vector <Collision3D> collisions;

	void cast(std::vector <Object3D*> objects);
	Collision3D get_closest_collision();
	bool collides(std::vector<Object3D*> objects);
};

#endif