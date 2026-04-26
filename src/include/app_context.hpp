#pragma once
#include "SDL3/SDL_render.h"
#include "gui_label.hpp"
#include <SDL3/SDL_video.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>


class AppContext{
public:
SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

std::vector<Label> labels;

~AppContext();

private:

};



