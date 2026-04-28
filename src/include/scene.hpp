#pragma once

#include "app_context.hpp"


class AppContext;

class Scene{

public:

virtual ~Scene() = default;

virtual void init(AppContext *app_ctx) = 0;
virtual void update(AppContext *app_ctx) = 0;
virtual void handle_events(AppContext *app_ctx, SDL_Event *event) = 0;


};

void change_scene(AppContext *app_ctx, int scene);