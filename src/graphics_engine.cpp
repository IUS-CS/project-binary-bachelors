#include "graphics_engine.h"
#include "graphics_component.h"

#include <iostream>
#include <string>

constexpr char kGameTitle[] = "Legend of Zordo";

GraphicsEngine::GraphicsEngine() {}

GraphicsEngine::~GraphicsEngine() {
  SDL_DestroyWindow(GraphicsComponent::Get().window);
  SDL_Quit();
}

void GraphicsEngine::DrawNextFrame() {
  // SDL function to display the renderer to the screen.
  SDL_RenderPresent(GraphicsComponent::Get().renderer);
  // SDL function to clear the renderer so we can start drawing a new blank
  // frame.
  SDL_RenderClear(GraphicsComponent::Get().renderer);
}

void GraphicsEngine::Run(GameObject &object) {
  if (object.sprite && object.location) {
    // This rect is where the sprite is on the spritesheet.
    const SDL_Rect &source = object.sprite->sprite_rect;
    // This rect is where we want to display the source image on the renderer.
    // Sidenote: The width and height are multiplied by 2 to scale the image,
    // making it double its original size.
    const SDL_Rect destination = {
        .x = object.location->coordinates.x,
        .y = object.location->coordinates.y,
        .w = object.sprite->sprite_rect.w * object.sprite->scale,
        .h = object.sprite->sprite_rect.h * object.sprite->scale};

    // This is the SDL function that adds the source sprite to the destination
    // rect on the renderer.
    SDL_RenderCopy(
        GraphicsComponent::Get().renderer,
        GraphicsComponent::Get().textures.at(object.sprite->sprite_sheet_name),
        &source, &destination);
  }
}
