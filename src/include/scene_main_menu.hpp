#pragma once
#include "gui_button.hpp"
#include "gui_label.hpp"
#include "scene.hpp"
#include <vector>

class SceneMainMenu : public Scene{
public:
std::vector<Label> labels;
std::vector<Button> buttons;

void init(AppContext *app_ctx) override;
void update(AppContext *app_ctx) override;
void handle_events(AppContext *app_ctx, SDL_Event *event) override;

};