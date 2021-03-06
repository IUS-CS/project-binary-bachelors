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
  SDL_RenderPresent(GraphicsComponent::Get().renderer);
  SDL_RenderClear(GraphicsComponent::Get().renderer);
}

void GraphicsEngine::AddSprite(const SpriteComponent &sprite,
                               const LocationComponent &location) {
  const SDL_Rect &source = sprite.sprite_rect;
  const SDL_Rect destination = {.x = location.x_,
                                .y = location.y_,
                                .w = sprite.sprite_rect.w * 2,
                                .h = sprite.sprite_rect.h * 2};

  SDL_RenderCopy(GraphicsComponent::Get().renderer,
                 GraphicsComponent::Get().textures.at(sprite.sprite_sheet_name),
                 &source, &destination);
}
