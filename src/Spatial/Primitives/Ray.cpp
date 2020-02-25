#include "Ray.h"
#include <cmath>
using namespace std;

Ray::Ray(): from(Vector3D(0,0,0)), to(Vector3D(0,0,0)){}

Ray::Ray(Vector3D from_, Vector3D to_): from(from_), to(to_){}

void Ray::cast(vector <Object3D*> objects){

	for(int i=0; i<objects.size(); i++){

		Vector3D intersection_point = objects[i]->intersects_ray(from,to);
		if (intersection_point != null_vector){

			collisions.push_back(Collision3D(objects[i], intersection_point));
		}
	}
}

Collision3D Ray::get_closest_collision(){

	Collision3D closest_collision;

	float min_distance = INFINITY;

	for(int i=0; i<collisions.size(); i++){

		float distance = from.distance_to(collisions[i].collision_point);

		if(distance < min_distance){

			min_distance = distance;
			closest_collision = collisions[i];
		}
	}

	return closest_collision;
}

bool Ray::collides(vector <Object3D*> objects){

	for(int i=0; i<objects.size(); i++){

		Vector3D intersection_point = objects[i]->intersects_ray(from, to);

		if(intersection_point != null_vector) return true;
	}

	return false;

}