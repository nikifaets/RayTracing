#include "Camera.h"
#include <iostream>
using namespace std;

Camera::Camera(){}

Camera::Camera(int screen_w_, int screen_h_) : screen_w(screen_w_), screen_h(screen_h_) {

	display.resize(screen_w);
	for(int i=0; i<screen_w; i++) display[i].resize(screen_h);
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