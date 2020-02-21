#ifndef SCENE_H
#define SCENE_H

#include "../Spatial/Object3D/Object3D.h"
#include "../Spatial/Object3D/Light/Light.h"
#include "../Spatial/Object3D/Camera/Camera.h"
#include <vector>

class Scene{

	std::vector <Object3D*> objects;
	std::vector <Light*> lights;
	Camera* camera;

public:

	Scene();
	void add_object(Object3D* object);
	void add_light(Light* light);
	void set_camera(Camera* camera_);
	void render();
};

#endif