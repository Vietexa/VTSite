#include "loop.hpp"
#include <SDL3/SDL_render.h>


bool loop(AppContext *app_ctx){


SDL_SetRenderDrawColor(app_ctx->renderer, 0, 255, 0, 255);
SDL_RenderClear(app_ctx->renderer);
app_ctx->labels.at(0).render();
app_ctx->buttons.at(0).render();
SDL_RenderPresent(app_ctx->renderer);

return true;
}
