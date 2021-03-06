#include "RayController.h"
#include <iostream>
#include <algorithm>

#include <math.h>

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

	float lambertian = cast_lambertian(collision);
	float shadow = cast_shadow(collision);

	color = color.scale(lambertian*shadow);
	color.threshold(0,255);

	return color;
}

float RayController::cast_lambertian(Collision3D collision){

	DirectionalLight* light = (DirectionalLight*)lights[0];
	Vector3D light_direction = light->direction.scale(-1);
	
	float light_intensity = light->intensity;

	Vector3D collision_point = collision.collision_point;
	Vector3D collider_center = collision.collider->translation;
	Vector3D collision_normal = collision_point - collider_center;

	float albedo = collision.collider->albedo;
	float normal_length = collision_normal.get_length();
	float light_direction_length = light_direction.get_length();

	float cos_angle = max(float(0), light_direction.normalized().dot(collision_normal.normalized()));

	
	return  (light_intensity * cos_angle * albedo);

}

float RayController::cast_shadow(Collision3D collision){

	const float eps = 1e-3;
	
	Vector3D light_direction = ((DirectionalLight*)lights[0])->direction.scale(-1);
	Vector3D collision_point = collision.collision_point + light_direction.scale(eps);

	Ray shadow_ray(collision_point, collision_point + light_direction);
	bool collides = shadow_ray.collides(objects);

	if(collides) return 0.4;

	return 1;
}