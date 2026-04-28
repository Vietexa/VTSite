#include "scene.hpp"
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
    app_ctx->scene_ptr->init(app_ctx);
}