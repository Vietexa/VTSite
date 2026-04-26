#pragma once
#include "SDL3/SDL_render.h"
#include "gui_button.hpp"
#include "gui_label.hpp"
#include <SDL3/SDL_video.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>


class AppContext{
public:
SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

float m_pos_x = 0;
float m_pos_y = 0;

std::vector<Label> labels;
std::vector<Button> buttons;

~AppContext();

private:

};



