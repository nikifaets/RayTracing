#ifndef RAYCONTROLLER_H
#define RAYCONTROLLER_H

#include "../Spatial/Object3D/Object3D.h"
#include "../Spatial/Object3D/Light/Light.h"
#include "../Spatial/Primitives/Ray.h"
#include "../Spatial/Primitives/Vector3D.h"
#include "../Spatial/Collision/Collision3D.h"
#include "../Spatial/Object3D/Light/DirectionalLight/DirectionalLight.h"
#include <vector>

class RayController{

	Ray starting_ray;
	float cast_lambertian(Collision3D collision);
	float cast_shadow();
	std::vector<Object3D*> objects;
	std::vector<Light*> lights;

public:

	RayController(Ray ray_from_pixel, std::vector <Object3D*> objects_, std::vector<Light*> lights_);
	Vector3D get_pixel_color();




};
#endif