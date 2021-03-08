#include "game.h"
#include "game_object.h"
#include "graphics_component.h"
#include "graphics_engine.h"
#include "input_component.h"
#include "input_engine.h"
#include "location_component.h"
#include "sprite_component.h"

Game::Game() {}

Game::~Game() {}

void Game::Run() {
  GameObject lonk;
  GraphicsEngine graphics_engine;
  InputEngine input_engine;
  SpriteComponent sprite;
  LocationComponent location;
  lonk.AddComponent(sprite);
  lonk.AddComponent(location);
  while (true) {
    frame_start_time_ms = SDL_GetTicks();
    graphics_engine.AddSprite(sprite, location);
    if (input_engine.Update(location) == 1) {
      return;
    }
    graphics_engine.DrawNextFrame();
    LimitFrameRate();
  }
}

void Game::LimitFrameRate() {
  int current_time_ms = SDL_GetTicks();
  int elapsed_time_ms = current_time_ms - frame_start_time_ms;
  if (elapsed_time_ms < 20) {
    SDL_Delay(20 - elapsed_time_ms);
  }
}
