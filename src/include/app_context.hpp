#pragma once
#include "SDL3/SDL_render.h"

#include <SDL3/SDL_video.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <memory>

#include "scene.hpp"

class Scene;

class AppContext{
public:
SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

Uint64 last_time;  // To store the timestamp of the previous frame
float delta_time;  // To store the calculated delta for the current frame

int current_scene = 0;

std::unique_ptr<Scene> scene_ptr;

~AppContext();

private:

};



