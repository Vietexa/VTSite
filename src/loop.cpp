#include "loop.hpp"
#include "SDL3/SDL_timer.h"
#include <SDL3/SDL_render.h>


bool loop(AppContext *app_ctx){

app_ctx->scene_ptr->update(app_ctx);

#ifndef __EMSCRIPTEN__
SDL_Delay(20);
#endif

return true;
}
