#include "graphics_component.h"
#include "data/texture_data.h"
#include "utils.h"

#include <SDL2/SDL_image.h>

// Static variables must be initialized.
GraphicsComponent *GraphicsComponent::instance_ = nullptr;

GraphicsComponent &GraphicsComponent::Get() {
  if (!instance_) {
    // Here is where you'll do all the creating of the SDL stuff.
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(1000, 596, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Legend of Zordo");
    // Populate all textures.
    std::unordered_map<std::string, SDL_Texture *> textures;
    for (const auto &sprite_sheet : kSpriteSheets) {
      SDL_Surface *surface = IMG_Load(GetAssetPath(sprite_sheet).c_str());
      SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
      textures.insert_or_assign(sprite_sheet, texture);
    }
    instance_ = new GraphicsComponent{window, renderer, textures};
  }
  return *instance_;
}
