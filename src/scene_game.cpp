
#include "SDL3/SDL_render.h"
#include "scene.hpp"
#include <scene_game.hpp>


void SceneGame::init(AppContext *app_ctx){
add_label(app_ctx->renderer, 500, 500, "This is scene 2");
add_button(app_ctx->renderer, 1000, 1000, "Test button 2");
}

void SceneGame::update(AppContext *app_ctx){
SDL_SetRenderDrawColor(app_ctx->renderer, 0, 255, 0, 255);
SDL_RenderClear(app_ctx->renderer);
labels.at(0).render();
buttons.at(0).render();
SDL_RenderPresent(app_ctx->renderer);



}

void SceneGame::handle_events(AppContext *app_ctx, SDL_Event *event){

    if(buttons.at(0).was_clicked(event)){
        change_scene(app_ctx, 0);
    }

}

