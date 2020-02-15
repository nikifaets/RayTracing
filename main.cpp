#include "Cube.h"
#include <iostream>
#include "MainWindow.h"
#include "Camera.h"
#include "Vector3D.h"
#include "Sphere.h"
#include <cmath>
using namespace std;

int main(int argc, char * argv[]){

	vector <Object3D*> objects;

	Sphere sphere(Vector3D(0,0,0), 300);

	sphere.center = Vector3D(0,0,0);
	objects.push_back(&sphere);

    MainWindow window(200, 400);

    Camera main_camera(200,400);

    main_camera.translation = Vector3D(-20, -100, -100);
    main_camera.set_objects(objects);
    main_camera.draw();
    window.set_camera(&main_camera);

    window.render_display();

    for(int i=0; i<100; i++){

    	main_camera.translation =  main_camera.translation + Vector3D(-1,0,0);
    	main_camera.draw();
    	window.render_display();

    	SDL_Delay(10);
    }

    SDL_Event event;   

    while(!(event.type == SDL_QUIT)){
        SDL_Delay(10);  
        SDL_PollEvent(&event);  
    }
}
