#include "Scene.h"

Scene::Scene(){}

void Scene::add_object(Object3D* object){

	objects.push_back(object);
}

void Scene::add_light(Light* light){

	lights.push_back(light);
}

void Scene::set_camera(Camera* camera_){

	camera = camera_;
	camera->set_lights(lights);
	camera->set_objects(objects);
}

void Scene::render(){

	camera->draw();
}