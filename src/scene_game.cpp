
#include "SDL3/SDL_render.h"
#include <scene_game.hpp>


void SceneGame::init(AppContext *app_ctx){
    labels.emplace_back(app_ctx->renderer,
     std::string("Hello from the other side"),
     std::string("assets/fonts/default.ttf"),
    50,
    SDL_Color{255,255,255,255},
    500,
    500);
}

void SceneGame::update(AppContext *app_ctx){
SDL_SetRenderDrawColor(app_ctx->renderer, 0, 255, 0, 255);
SDL_RenderClear(app_ctx->renderer);
labels.at(0).render();
SDL_RenderPresent(app_ctx->renderer);



}

void SceneGame::handle_events(AppContext *app_ctx, SDL_Event *event){


}

