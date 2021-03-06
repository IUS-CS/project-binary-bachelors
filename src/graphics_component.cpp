#include "graphics_component.h"
#include "data/texture_data.h"
#include "utils.h"

#include <SDL2/SDL_image.h>

GraphicsComponent *GraphicsComponent::instance_ = nullptr;

GraphicsComponent &GraphicsComponent::Get() {
  // If the single instance of the object has not been created yet, it enters
  // the loop to create this object. This if statement is like the constructor
  // for this object.
  if (!instance_) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    // SDL function to create a window.
    SDL_CreateWindowAndRenderer(1000, 596, 0, &window, &renderer);
    // SDL function to add a title at the top of the window.
    SDL_SetWindowTitle(window, "Legend of Zordo");
    std::unordered_map<std::string, SDL_Texture *> textures;
    // This for loop is where all of the textures for the game are automatically
    // generated.
    for (const auto &sprite_sheet : kSpriteSheets) {
      SDL_Surface *surface = IMG_Load(GetAssetPath(sprite_sheet).c_str());
      SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
      textures.insert_or_assign(sprite_sheet, texture);
    }
    // Creates the singleton.
    instance_ = new GraphicsComponent{window, renderer, textures};
  }
  // If the object has already been created, the return statement is all that
  // this function will do. It will return a reference to the singleton.
  return *instance_;
}
