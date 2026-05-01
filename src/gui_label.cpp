#include "gui_label.hpp"

Label::Label(SDL_Renderer* renderer,
          const std::string& text,
          const std::string& fontPath,
          int fontSize,
          SDL_Color color,
          float x,
          float y)
        : renderer(renderer), text(text), color(color), x(x), y(y)
    {
        font = TTF_OpenFont(fontPath.c_str(), fontSize);
        texture = nullptr;
        updateTexture();
    }

    Label::~Label() {
        if (texture) SDL_DestroyTexture(texture);
        if (font) TTF_CloseFont(font);
    }

     void Label::setText(const std::string& newText) {
        text = newText;
        updateTexture();
    }

    void Label::setColor(SDL_Color newColor) {
        color = newColor;
        updateTexture();
    }

     void Label::setPosition(float newX, float newY) {
        x = newX;
        y = newY;
    }

    void Label::increase_pos_x(float amount) {
        x += amount; 
    }

    void Label::increase_pos_y(float amount) {
        y += amount; 
    }
      

    void Label::render() {
        if (!texture) return;
        SDL_FRect dst = { x, y, width, height };
        SDL_RenderTexture(renderer, texture, nullptr, &dst);
    }

    void Label::updateTexture() {
        if (texture) {
            SDL_DestroyTexture(texture);
            texture = nullptr;
        }

        if (!font || text.empty()) return;

        SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(),text.length(), color);
        if (!surface) return;

        texture = SDL_CreateTextureFromSurface(renderer, surface);
        width = static_cast<float>(surface->w);
        height = static_cast<float>(surface->h);

        SDL_DestroySurface(surface);
    }

