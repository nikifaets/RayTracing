#include "RayController.h"
#include "../Spatial/Collision/Collision3D.h"
using namespace std;

RayController::RayController(Ray ray_from_pixel, vector<Object3D*> objects_, vector<Light*> lights_) : starting_ray(ray_from_pixel), objects(objects_), lights(lights_){}

Vector3D RayController::get_pixel_color(){

	starting_ray.cast(objects);

	Collision3D collision = starting_ray.get_closest_collision();

	if(collision.collision_point == null_vector){

		return Vector3D(255,255,255);
	}

	Object3D* collider = collision.collider;
	Vector3D color = collider->color;

	return color;
}