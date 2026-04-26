#pragma once

#include <SDL3/SDL_render.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>

class Label {
public:
    Label(SDL_Renderer* renderer,
          const std::string& text,
          const std::string& fontPath,
          int fontSize,
          SDL_Color color,
          float x,
          float y);

    ~Label();
    void setText(const std::string& newText);
    void setColor(SDL_Color newColor);
    void setPosition(float newX, float newY);
    void render();

private:
    void updateTexture();

    SDL_Renderer* renderer;
    TTF_Font* font;
    SDL_Texture* texture;

    std::string text;
    SDL_Color color;

    float x, y;
    float width, height;
};