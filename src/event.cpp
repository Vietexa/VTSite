
#include "event.hpp"
#include "SDL3/SDL_events.h"
#include "app_context.hpp"

bool process_event(AppContext *app_ctx, SDL_Event *event){

app_ctx->scene_ptr->handle_events(app_ctx, event);


return true;
}