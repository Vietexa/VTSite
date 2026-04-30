
#include "app_context.hpp"

AppContext::~AppContext() {
        scene_ptr.reset();
        TTF_Quit();
        if (renderer) SDL_DestroyRenderer(renderer);
        if (window) SDL_DestroyWindow(window);
    }