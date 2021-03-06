#ifndef GRAPHICS_COMPONENT_H
#define GRAPHICS_COMPONENT_H

#include <SDL2/SDL.h>
#include <unordered_map>

// GraphicsComponent.h

/*
This component is kind of confusing. This component is what is called a
singleton. It kind of works like a global variable, but it's not a global
variable. In the code, only one of these components will exist and every other
part of the code can access this component by using GraphicsComponent::Get().
You will see where I have already used this. To get an even better
understanding of how this works, watch some youtube videos about singletons.
*/
struct GraphicsComponent {
  // The window where the game is played.
  SDL_Window *const window;
  // You add an image to the renderer and then present the renderer to display
  // the new frame on the screen. You can think of the renderer as a drawing on
  // paper, and it appearing on the screen as showing the drawing to a camera.
  SDL_Renderer *const renderer;
  // This is a map of all the texture sheets for the game.
  const std::unordered_map<std::string, SDL_Texture *> textures;

  // Returns the graphics component singleton.
  static GraphicsComponent &Get();

private:
  // This is a pointer to the singleton.
  static GraphicsComponent *instance_;
};
#endif
