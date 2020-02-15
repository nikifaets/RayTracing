#ifndef CAMERA_H
#define CAMERA_H

#include "Object3D.h"
#include <vector>
#include <array>
#include "Sphere.h"

class Camera : public Object3D{

public:

	Camera();
	Camera(int screen_w_, int screen_h_); 
	void render_display(std::vector <Object3D> objects_list);
	std::vector <std::vector <std::array <int, 3> > > get_display();
	void fill_display_black();
	void print_display();
	void set_objects(std::vector<Object3D*> objects_);
	void draw();

private:

	int screen_w = 0;
	int screen_h = 0;
	std::vector <std::vector < std::array<int, 3> > > display;
	std::vector <Object3D*> objects;
};

#endif