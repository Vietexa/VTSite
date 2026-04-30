#pragma once

#include "app_context.hpp"
#include "gui_button.hpp"
#include "gui_label.hpp"
#include <vector>


class AppContext;

class Scene{

public:

std::vector<Label> labels;
std::vector<Button> buttons;

virtual ~Scene() = default;

virtual void init(AppContext *app_ctx) = 0;
virtual void update(AppContext *app_ctx) = 0;
void add_button(
 SDL_Renderer *renderer,
 float x,
 float y,
 std::string text, 
 std::string font = "assets/fonts/default.ttf", 
 int font_size = 50, 
 SDL_Color color = {255,255,255,255},
 SDL_Color btn_color = {0,0,0,255}
 );

void add_label(
 SDL_Renderer *renderer,
 float x,
 float y,
 std::string text, 
 std::string font = "assets/fonts/default.ttf", 
 int font_size = 50, 
 SDL_Color color = {255,255,255,255});

virtual void handle_events(AppContext *app_ctx, SDL_Event *event) = 0;


};

void change_scene(AppContext *app_ctx, int scene);