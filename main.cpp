#include "Cube.h"
#include "Object3D.h"
#include <iostream>
#include "MainWindow.h"
#include "Camera.h"

using namespace std;

int main(int argc, char * argv[]){

	Cube cube;
	std :: cout << cube.obj_type;

    MainWindow window(200, 400);

    Camera main_camera(200,400);
    window.set_camera(&main_camera);
    main_camera.fill_display_black();
    window.render_display();

    SDL_Event event;   

    while(!(event.type == SDL_QUIT)){
        SDL_Delay(10);  
        SDL_PollEvent(&event);  
    }
}
