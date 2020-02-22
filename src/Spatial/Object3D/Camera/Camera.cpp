#include "Camera.h"
#include "../../Collision/Collision3D.h"
#include "../../Primitives/Ray.h"
#include "../../../RayController/RayController.h"
#include "cmath"
#include <iostream>
using namespace std;

Camera::Camera(){}

Camera::Camera(int screen_h_, int screen_w_) : screen_w(screen_w_), screen_h(screen_h_) {

	display.resize(screen_h);
	for(int i=0; i<screen_h; i++) display[i].resize(screen_w);
}

vector <vector <array <int, 3> > > Camera::get_display(){

	return display;
}

void Camera::fill_display_black(){

	for(int i=0; i<display.size(); i++){

		for(int j=0; j<display[i].size(); j++){

			display[i][j] = {255,0,0};
		}
	}
}

void Camera::print_display(){

	for(int i=0; i<display.size(); i++){

		for(int j=0; j<display[i].size(); j++){

			cout << display[i][j][0] << " " << display[i][j][1] << " " << display[i][j][2] << endl;
		}
	}
}

void Camera::set_objects(vector <Object3D*> objects_){

	objects = objects_;
}

void Camera::set_lights(vector <Light*> lights_){

	lights = lights_;
}

void Camera::draw(){

	Vector3D eye;
	eye = eye - basis.x.scale(300);
	eye = eye + translation;

	for(int i=0; i<display.size(); i++){

		for(int j=0; j<display[i].size(); j++){

			float y = j;
			float z = -i;

			Vector3D offset_y(0, -screen_w/2., 0);
			Vector3D offset_z(0,0, screen_h/2.);

			Vector3D pixel(0,y,z);
			pixel = pixel + offset_z + offset_y;
			//rotation
			pixel = basis.multiply_vector(pixel);
			
			//translation
			pixel = pixel + translation; 
			
			Vector3D from = pixel;
			Vector3D dir = (pixel - eye).normalized();
			Vector3D to = pixel + dir;

			Ray ray(from, to);

			RayController ray_controller(ray, this->objects, this->lights);
			Vector3D color = ray_controller.get_pixel_color();

			display[i][j] = {color.x, color.y, color.z};

		}
	}
}