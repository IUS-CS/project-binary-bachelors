#include "game.h"
#include "game_object.h"
#include "graphics_component.h"
#include "graphics_engine.h"
#include "location_component.h"
#include "sprite_component.h"

#include <iostream>
#include <sstream>
#include <string>

Game::Game() {}

Game::~Game() {}

void Game::Run() {
  GameObject lonk;
  GraphicsEngine graphics_engine;
  SpriteComponent sprite;
  LocationComponent location;
  // This is a temporary loop. There is currently no way to close the window so
  // this loop just opens the window until i = 300. Then the program ends.
  for (int i = 0; i < 300; i++) {
    graphics_engine.AddSprite(sprite, location);
    graphics_engine.DrawNextFrame();
    std::cout << i << std::endl;
  }
}
