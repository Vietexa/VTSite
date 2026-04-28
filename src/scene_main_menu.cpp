
#include "scene_main_menu.hpp"
#include "app_context.hpp"
#include "scene.hpp"

void SceneMainMenu::init(AppContext *app_ctx){
labels.emplace_back(app_ctx->renderer,
     std::string("Hello there!"),
     std::string("assets/fonts/default.ttf"),
    50,
    SDL_Color{255,255,255,255},
    500,
    500);

buttons.emplace_back(app_ctx->renderer,std::string("hello there"), std::string("assets/fonts/default.ttf"),50, SDL_Color{255,255,255,255}, 1000, 1000, SDL_Color{255,0,0,255} );
}

void SceneMainMenu::update(AppContext *app_ctx){

SDL_SetRenderDrawColor(app_ctx->renderer, 0, 255, 0, 255);
SDL_RenderClear(app_ctx->renderer);
labels.at(0).render();
buttons.at(0).render();
SDL_RenderPresent(app_ctx->renderer);



}

void SceneMainMenu::handle_events(AppContext *app_ctx, SDL_Event *event){

    if (buttons.at(0).was_clicked(event)){
        SDL_Log("The button was clicked.\n");
        change_scene(app_ctx, 1);
    }


}





