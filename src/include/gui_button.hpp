#pragma once
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_stdinc.h"
#include "gui_label.hpp"

class Button : public Label{

public:
Button(SDL_Renderer* renderer,
          const std::string& text,
          const std::string& fontPath,
          int fontSize,
          SDL_Color color,
          float x,
          float y,
          SDL_Color btn_color);

    ~Button();
    void render() override;
    void setText(const std::string& newText) override;
    bool was_clicked(SDL_Event *event);
    void update_layout();
    private:

    void was_pressed(SDL_Event *event);

    SDL_Color m_btn_color;

    Uint8 red = 0;
    Uint8 green = 0;
    Uint8 blue = 0;
    Uint8 alpha = 0;

    float button_width = 0;
    float button_height = 0;

    bool m_pressed = false;
    bool m_dirty = false; //Mark the layout as dirty when it changes
};