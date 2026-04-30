
#include <memory>
#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "app_context.hpp"
#include "loop.hpp"
#include "event.hpp"
#include "element_init.hpp"
#include "scene_main_menu.hpp"

static bool init_window_and_renderer(AppContext *app_ctx){

app_ctx->window = SDL_CreateWindow("Site",1920, 1080, SDL_WINDOW_HIGH_PIXEL_DENSITY);

    if (!app_ctx->window) {
        SDL_Log("Couldn't create the window: %s", SDL_GetError());  
        return false;    
    }

    app_ctx->renderer = SDL_CreateRenderer(app_ctx->window, NULL);

    if (!app_ctx->renderer){
        SDL_Log("Couldn't create the renderer: %s", SDL_GetError());  
        return false;    
    }

    return true;

}



SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]){
   
    //The context of the app
    AppContext *app_ctx = new AppContext;
    *appstate = app_ctx;

    //Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    //Initialize the window and the renderer
    if (!init_window_and_renderer(app_ctx)){
        return SDL_APP_FAILURE;
    }

    #ifndef __EMSCRIPTEN__
    SDL_SetWindowFullscreen(app_ctx->window, true);
    #endif

    SDL_SetRenderLogicalPresentation(app_ctx->renderer, 1920, 1080,SDL_LOGICAL_PRESENTATION_STRETCH);

    //Initalize SDL_TTF
    if (!TTF_Init()) {
        SDL_Log("Couldn't initialize the TTF %s", SDL_GetError());
        return SDL_APP_FAILURE;
     }
    app_ctx->scene_ptr = std::make_unique<SceneMainMenu>();

     initalize_elements(app_ctx);
     
     

    return SDL_APP_CONTINUE; 
}


SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
AppContext *app_ctx = static_cast<AppContext*>(appstate);

    if(!process_event(app_ctx, event)) return SDL_APP_FAILURE;
    if (event->type == SDL_EVENT_QUIT) return SDL_APP_SUCCESS;

    return SDL_APP_CONTINUE; 
 }


SDL_AppResult SDL_AppIterate(void *appstate){  
   AppContext *app_ctx = static_cast<AppContext*>(appstate);
    
    if(!loop(app_ctx)) return SDL_APP_FAILURE;

    return SDL_APP_CONTINUE; 
}


void SDL_AppQuit(void *appstate, SDL_AppResult result){

    //cleanup the resources used and close
    AppContext *app = static_cast<AppContext *>(appstate);

    //Delete app and let the destructor run
    delete app;



}
