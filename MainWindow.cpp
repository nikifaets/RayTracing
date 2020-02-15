#include "MainWindow.h"
#include <iostream>
using namespace std;
MainWindow :: MainWindow(int height_, int width_) : height(height_), width(width_){

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	}

MainWindow :: ~MainWindow(){

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void MainWindow :: render_display(){

	int opacity = 255;
	vector <vector <array <int,3> > > display = main_camera->get_display();
	for(int i=0; i<display.size(); i++){

		for(int j=0; j<display[i].size(); j++){

			array <int,3> pixel = display[i][j];

			SDL_SetRenderDrawColor(renderer, pixel[0], pixel[1], pixel[2], opacity);
			SDL_RenderDrawPoint(renderer, j,i);
		}
	}

	SDL_RenderPresent(renderer);
}

void MainWindow :: draw_circle(int center_x, int center_y, int radius){

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	for(int x=center_x-radius; x<=center_x+radius; x++){
	    for(int y=center_y-radius; y<=center_y+radius; y++){
	        if((std::pow(center_y-y,2)+std::pow(center_x-x,2)) <= 
	            std::pow(radius,2)){
	            SDL_RenderDrawPoint(renderer, x, y);
	        }
	    }
	}

	SDL_RenderPresent(renderer);
}

void MainWindow :: set_camera(Camera *camera_){

	main_camera = camera_;
}
