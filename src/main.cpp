#include <iostream>
#include "MainWindow.h"
#include "Spatial/Camera/Camera.h"
#include "Spatial/Primitives/Vector3D.h"
#include "Spatial/Object3D/Sphere.h"
#include <cmath>
using namespace std;

int main(int argc, char * argv[]){

	vector <Object3D*> objects;

	Sphere sphere(Vector3D(100,0,0), 50);
    Sphere sphere1(Vector3D(150, 0, 0), 120);
	//sphere.center = Vector3D(0,0,0);
	objects.push_back(&sphere);
    //objects.push_back(&sphere1);

    sphere.color = Vector3D(255,0,0);
    sphere1.color = Vector3D(0,255,0);

    MainWindow window(200, 400);

    Camera main_camera(200,400);

    main_camera.translation = Vector3D(-300, 0, 0);
    main_camera.set_objects(objects);

    //main_camera.basis.print_matrix();
    //main_camera.rotate_z(1.2);
    main_camera.draw();
    window.set_camera(&main_camera);

    window.render_display();

    for(int i=0; i<200; i++){

    	//sphere.translation = sphere.translation + Vector3D(0,-9,1);
    	//main_camera.translation = main_camera.translation + Vector3D(0,sin(i),0).scale(80);
    	main_camera.rotate_z(0.1);
    	main_camera.draw();
    	window.render_display();

    	SDL_Delay(1);
    }

    SDL_Event event;   

    while(!(event.type == SDL_QUIT)){
        SDL_Delay(10);  
        SDL_PollEvent(&event);  
    }
}
