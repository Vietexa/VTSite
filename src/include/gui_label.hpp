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

    virtual ~Label();
    virtual void setText(const std::string& newText);
    void setColor(SDL_Color newColor);
    void setPosition(float newX, float newY);
    virtual void render();

private:
    void updateTexture();
protected:
    SDL_Renderer* renderer = nullptr;
    TTF_Font* font = nullptr;
    SDL_Texture* texture = nullptr;

    std::string text = "";
    SDL_Color color = {};

    float x = 0;
    float y = 0;
    float width = 0;
    float height = 0;
};