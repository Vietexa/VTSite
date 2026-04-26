#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_render.h"
#include "gui_label.hpp"
#include <gui_button.hpp>

Button::Button(SDL_Renderer* renderer,
          const std::string& text,
          const std::string& fontPath,
          int fontSize,
          SDL_Color color,
          float x,
          float y,
          SDL_Color btn_color
        )
          : Label(renderer, text, fontPath, fontSize, color, x, y), m_btn_color(btn_color){
            
            //the colors
            red = btn_color.r;
            green = btn_color.g;
            blue = btn_color.b;
            alpha = btn_color.a;
            m_dirty = true;
   }

Button::~Button() { }


   void Button::setText(const std::string& newText) {
    Label::setText(newText); 
    m_dirty = true;          
}


 bool Button::was_clicked(SDL_Event *event){
    update_layout();

    SDL_Event e = *event;
    SDL_ConvertEventToRenderCoordinates(renderer, &e);

    if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        
        float mx = e.button.x;
        float my = e.button.y;

        if (mx >= x && mx <= x + button_width &&
            my >= y && my <= y + button_height) {
            m_pressed = true;
        }
    }

    if (e.type == SDL_EVENT_MOUSE_BUTTON_UP) {
        float mx = e.button.x;
        float my = e.button.y;

        if (m_pressed &&
            mx >= x && mx <= x + button_width &&
            my >= y && my <= y + button_height) {

            m_pressed = false;
            return true; 
        }

        m_pressed = false;
    }

    return false;
    
 }

 void Button::update_layout() {
     if (!m_dirty) return;
    float padding_x = 10.0f;
    float padding_y = 5.0f;

    button_width  = width  + padding_x * 2;
    button_height = height + padding_y * 2;
    m_dirty = false;
}

 void Button::render(){

    update_layout();

    if (!texture) return;

    // Draw button background
    SDL_FRect buttonRect = { x, y, button_width, button_height };
    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
    SDL_RenderFillRect(renderer, &buttonRect); 

    // Center text inside button
    SDL_FRect textRect = {
        x + (button_width - width) / 2.0f,
        y + (button_height - height) / 2.0f,
        width,
        height
    };

    SDL_RenderTexture(renderer, texture, nullptr, &textRect);
 }

 

