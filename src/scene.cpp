#include "scene.hpp"
#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_render.h"
#include "app_context.hpp"
#include "scene_game.hpp"
#include "scene_main_menu.hpp"
#include <memory>

void change_scene(AppContext *app_ctx, int scene){
    if (scene == app_ctx->current_scene) return;

    switch (scene){
        
        case 0:
        app_ctx->current_scene = 0;
        app_ctx->scene_ptr = std::make_unique<SceneMainMenu>();
        break;

        case 1:
        app_ctx->current_scene = 1;
        app_ctx->scene_ptr = std::make_unique<SceneGame>();
        break;
        
    }
    app_ctx->scene_ptr->init(app_ctx); //Initalize the elements after changing the scene
}

void Scene::add_button(SDL_Renderer *renderer,
 float x,
 float y,
 std::string text, 
 std::string font, 
 int font_size, 
 SDL_Color color,
SDL_Color btn_color){

buttons.emplace_back(renderer, text,font,font_size, color, x ,y, btn_color);

}


void Scene::add_label(SDL_Renderer *renderer,
 float x,
 float y,
 std::string text, 
 std::string font, 
 int font_size, 
 SDL_Color color){
    
labels.emplace_back(renderer, text,font,font_size, color, x ,y);
}