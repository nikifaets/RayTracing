#include "Camera.h"
#include "Collision3D.h"
#include "Ray.h"
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

void Camera:: set_objects(vector <Object3D*> objects_){

	objects = objects_;
}

void Camera::draw(){

	Vector3D eye(-200,0,0);
	eye = basis.multiply_vector(eye);
	eye = eye + translation;

	for(int i=0; i<display.size(); i++){

		for(int j=0; j<display[i].size(); j++){

			float y = j;
			float z = -i;

			Vector3D offset_y(0, -screen_w/2., 0);
			Vector3D offset_z(0,0, screen_h/2.);

			Vector3D pixel(0,y,z);

			//rotation
			pixel = basis.multiply_vector(pixel);
			
			//translation
			pixel = pixel + offset_y + offset_z + translation; 
			
			Vector3D from = eye;
			Vector3D to = pixel;

			Ray ray(from, to);
			ray.cast(objects);

			Collision3D closest_collision = ray.get_closest_collision();

			if(closest_collision.collision_point == null_vector){

				display[i][j] = {0,0,0};
			}

			else{

				display[i][j] = {255,255,255};
			}
		}
	}
}