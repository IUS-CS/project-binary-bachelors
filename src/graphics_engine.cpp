#include "graphics_engine.h"
#include "graphics_component.h"

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

void GraphicsEngine::AddSprite(const SpriteComponent &sprite,
                               const LocationComponent &location) {
  // This rect is where the sprite is on the spritesheet.
  const SDL_Rect &source = sprite.sprite_rect;
  // This rect is where we want to display the source image on the renderer.
  // Sidenote: The width and height are multiplied by 2 to scale the image,
  // making it double its original size.
  const SDL_Rect destination = {.x = location.x_,
                                .y = location.y_,
                                .w = sprite.sprite_rect.w * 2,
                                .h = sprite.sprite_rect.h * 2};

  // This is the SDL function that adds the source sprite to the destination
  // rect on the renderer.
  SDL_RenderCopy(GraphicsComponent::Get().renderer,
                 GraphicsComponent::Get().textures.at(sprite.sprite_sheet_name),
                 &source, &destination);
}
