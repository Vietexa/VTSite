
#include "element_init.hpp"



void initalize_elements(AppContext *app_ctx){

app_ctx->labels.emplace_back(app_ctx->renderer,
     std::string("Hello there!"),
     std::string("assets/fonts/default.ttf"),
    50,
    SDL_Color{255,255,255,255},
    500,
    500);

app_ctx->buttons.emplace_back(app_ctx->renderer,std::string("hello there"), std::string("assets/fonts/default.ttf"),50, SDL_Color{255,255,255,255}, 1000, 1000, SDL_Color{255,0,0,255} );

}