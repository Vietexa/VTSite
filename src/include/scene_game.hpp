#pragma once

#include "scene.hpp"


class SceneGame : public Scene{
public:

void init(AppContext *app_ctx) override;
void update(AppContext *app_ctx) override;
void handle_events(AppContext *app_ctx, SDL_Event *event) override;

};