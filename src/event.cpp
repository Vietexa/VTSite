
#include "event.hpp"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_pixels.h"
#include "app_context.hpp"

bool process_event(AppContext *app_ctx, SDL_Event *event){


if(app_ctx->buttons.at(0).was_clicked(event)){
app_ctx->buttons.at(0).setText("You're a nice guy!");
SDL_Log("Button was clicked\n");
}



switch (event->type){

    case SDL_EVENT_MOUSE_BUTTON_DOWN:
    if(event->button.button == SDL_BUTTON_LEFT){
        app_ctx->m_pos_x = event->button.x;
        app_ctx->m_pos_y = event->button.y;
    }
    break;


}


return true;
}