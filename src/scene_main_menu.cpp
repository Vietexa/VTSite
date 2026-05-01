
#include "scene_main_menu.hpp"
#include "app_context.hpp"
#include "scene.hpp"

void SceneMainMenu::init(AppContext *app_ctx){
add_label(app_ctx->renderer, 500, 500, "This is scene 1");
add_button(app_ctx->renderer,100, 1000, "Test button");
}

void SceneMainMenu::update(AppContext *app_ctx){

    if (buttons.at(0).x < 1050){
    buttons.at(0).increase_pos_x(500 * app_ctx->delta_time);
}

SDL_SetRenderDrawColor(app_ctx->renderer, 0, 0, 0, 255);
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





