#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <SDL.h>
#include "Camera.h"

class MainWindow{

public:

    MainWindow(int height_, int width_);

    ~MainWindow();

  	void set_camera(Camera *camera_);

  	void render_display();

private:

    int height;
    int width;
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
    Camera *main_camera = nullptr;
};

#endif