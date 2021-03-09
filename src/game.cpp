#include "game.h"
#include "game_object.h"
#include "graphics_component.h"
#include "graphics_engine.h"
#include "input_component.h"
#include "input_engine.h"

Game::Game() {}

Game::~Game() {}

void Game::Run() {
  GameObject lonk;
  GraphicsEngine graphics_engine;
  InputEngine input_engine;
  lonk.location = LocationComponent(0, 100);
  lonk.sprite =
      SpriteComponent("lonk_sprite", {.x = 0, .y = 68, .w = 24, .h = 35});
  while (true) {
    frame_start_time_ms = SDL_GetTicks();
    graphics_engine.Run(lonk);
    if (input_engine.Run(lonk) == 1) {
      return;
    }
    graphics_engine.DrawNextFrame();
    LimitFrameRate();
  }
}

void Game::LimitFrameRate() {
  int current_time_ms = SDL_GetTicks();
  // This is the amount of time that has passed since the start of this frame.
  int elapsed_time_ms = current_time_ms - frame_start_time_ms;
  // The number 17 is used here because that is the amount of time that needs to
  // pass for each frame so that the frame rate will be 60 FPS (One second is
  // 1000 ms. 1000/17 = 59. So 17 is the number of ms we want to pass to get us
  // close to 60 FPS). So if the loop finishes faster than 17 ms, we make the
  // program wait to start the next frame.
  if (elapsed_time_ms < 17) {
    SDL_Delay(17 - elapsed_time_ms);
  }
}
