#include <iostream>
#include "MainWindow.h"
#include "Spatial/Object3D/Camera/Camera.h"
#include "Spatial/Primitives/Vector3D.h"
#include "Spatial/Object3D/Sphere.h"
#include "Scene/Scene.h"
#include "Spatial/Object3D/Light/DirectionalLight/DirectionalLight.h"
#include <cmath>
using namespace std;


int main(int argc, char * argv[]){

    Scene scene;

    Vector3D light_direction(1,1,1);
    DirectionalLight light(light_direction);

	Sphere sphere(Vector3D(400,0,0), 100);
    Sphere sphere1(Vector3D(220, 250, 0), 100);
    Sphere sphere2(Vector3D(300, -200, 0), 100);
    
    scene.add_object(&sphere1);
    scene.add_object(&sphere);
    scene.add_object(&sphere2);
    scene.add_light(&light);

    sphere.color = Vector3D(255,0,0);
    sphere1.color = Vector3D(0,255,0);
    sphere2.color = Vector3D(0,0,255);

    MainWindow window(400, 400);

    Camera main_camera(400,400);

    scene.set_camera(&main_camera);

    main_camera.translation = Vector3D(0, 0, 0);

    scene.render();
    window.set_camera(&main_camera);

    window.render_display();


    //test
    for(int i=0; i<150; i++){

        //sphere.translation = sphere.translation + Vector3D(0,30,0);
       // sphere1.translation = sphere1.translation + Vector3D(cos(i/10), -sin(i/10), sin(i/10)/3).scale(30);
    	//main_camera.translation = main_camera.translation + Vector3D(10,0,0);
        //main_camera.rotate_z(0.1);
        light.direction  = light.direction + Vector3D(0,20,0);
        cout << "frame " << endl;
        scene.render();
    	window.render_display();

    	SDL_Delay(20);
    }

    SDL_Event event;   

    while(!(event.type == SDL_QUIT)){
        SDL_Delay(10);  
        SDL_PollEvent(&event);  
    }
}
