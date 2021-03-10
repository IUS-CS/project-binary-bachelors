#include <vector>

#include "game.h"
#include "game_object.h"
#include "graphics_component.h"
#include "graphics_engine.h"
#include "input_component.h"
#include "input_engine.h"
#include "map_engine.h"
#include "movement_engine.h"

Game::Game() {}

Game::~Game() {}

void Game::Run() {
  GameObject map;
  map.is_map = true;
  int lvl1[20][31] = {{0, 3, 1, 2, 0, 2, 3, 1, 0, 0, 2, 1, 0, 3, 0, 1,
                       2, 3, 1, 3, 2, 0, 2, 0, 3, 0, 1, 2, 1, 0, 3},
                      {3, 2, 3, 0, 1, 3, 3, 2, 0, 1, 3, 1, 0, 2, 0, 1,
                       3, 1, 2, 1, 0, 3, 2, 1, 2, 3, 0, 1, 3, 0, 2},
                      {2, 1, 1, 3, 0, 2, 1, 3, 2, 0, 1, 0, 3, 1, 2, 0,
                       3, 1, 0, 0, 2, 3, 0, 1, 0, 2, 1, 3, 0, 2, 3},
                      {2, 1, 0, 2, 3, 2, 0, 3, 1, 2, 0, 1, 3, 0, 2, 3,
                       0, 2, 2, 0, 1, 3, 2, 1, 2, 0, 1, 3, 0, 0, 1},
                      {0, 3, 1, 2, 0, 2, 3, 1, 0, 0, 2, 1, 0, 3, 0, 1,
                       2, 3, 1, 3, 2, 0, 2, 0, 3, 0, 1, 2, 1, 0, 3},
                      {3, 2, 3, 0, 1, 3, 3, 2, 0, 1, 3, 1, 0, 2, 0, 1,
                       3, 1, 2, 1, 0, 3, 2, 1, 2, 3, 0, 1, 3, 0, 2},
                      {2, 1, 1, 3, 0, 2, 1, 3, 2, 0, 1, 0, 3, 1, 2, 0,
                       3, 1, 0, 0, 2, 3, 0, 1, 0, 2, 1, 3, 0, 2, 3},
                      {2, 1, 0, 2, 3, 2, 0, 3, 1, 2, 0, 1, 3, 0, 2, 3,
                       0, 2, 2, 0, 1, 3, 2, 1, 2, 0, 1, 3, 0, 0, 1},
                      {0, 3, 1, 2, 0, 2, 3, 1, 0, 0, 2, 1, 0, 3, 0, 1,
                       2, 3, 1, 3, 2, 0, 2, 0, 3, 0, 1, 2, 1, 0, 3},
                      {3, 2, 3, 0, 1, 3, 3, 2, 0, 1, 3, 1, 0, 2, 0, 1,
                       3, 1, 2, 1, 0, 3, 2, 1, 2, 3, 0, 1, 3, 0, 2},
                      {2, 1, 1, 3, 0, 2, 1, 3, 2, 0, 1, 0, 3, 1, 2, 0,
                       3, 1, 0, 0, 2, 3, 0, 1, 0, 2, 1, 3, 0, 2, 3},
                      {2, 1, 0, 2, 3, 2, 0, 3, 1, 2, 0, 1, 3, 0, 2, 3,
                       0, 2, 2, 0, 1, 3, 2, 1, 2, 0, 1, 3, 0, 0, 1},
                      {0, 3, 1, 2, 0, 2, 3, 1, 0, 0, 2, 1, 0, 3, 0, 1,
                       2, 3, 1, 3, 2, 0, 2, 0, 3, 0, 1, 2, 1, 0, 3},
                      {3, 2, 3, 0, 1, 3, 3, 2, 0, 1, 3, 1, 0, 2, 0, 1,
                       3, 1, 2, 1, 0, 3, 2, 1, 2, 3, 0, 1, 3, 0, 2},
                      {2, 1, 1, 3, 0, 2, 1, 3, 2, 0, 1, 0, 3, 1, 2, 0,
                       3, 1, 0, 0, 2, 3, 0, 1, 0, 2, 1, 3, 0, 2, 3},
                      {2, 1, 0, 2, 3, 2, 0, 3, 1, 2, 0, 1, 3, 0, 2, 3,
                       0, 2, 2, 0, 1, 3, 2, 1, 2, 0, 1, 3, 0, 0, 1},
                      {0, 3, 1, 2, 0, 2, 3, 1, 0, 0, 2, 1, 0, 3, 0, 1,
                       2, 3, 1, 3, 2, 0, 2, 0, 3, 0, 1, 2, 1, 0, 3},
                      {3, 2, 3, 0, 1, 3, 3, 2, 0, 1, 3, 1, 0, 2, 0, 1,
                       3, 1, 2, 1, 0, 3, 2, 1, 2, 3, 0, 1, 3, 0, 2},
                      {2, 1, 1, 3, 0, 2, 1, 3, 2, 0, 1, 0, 3, 1, 2, 0,
                       3, 1, 0, 0, 2, 3, 0, 1, 0, 2, 1, 3, 0, 2, 3},
                      {2, 1, 0, 2, 3, 2, 0, 3, 1, 2, 0, 1, 3, 0, 2, 3,
                       0, 2, 2, 0, 1, 3, 2, 1, 2, 0, 1, 3, 0, 0, 1}};
  map.map = MapComponent(lvl1);
  map.sprite =
      SpriteComponent("tile_map", {.x = 0, .y = 0, .w = 16, .h = 16}, 2);
  map.location = LocationComponent(0, 0);
  GameObject lonk;
  lonk.is_player = true;
  lonk.location = LocationComponent(0, 100);
  lonk.sprite =
      SpriteComponent("lonk_sprite", {.x = 0, .y = 0, .w = 48, .h = 48}, 3);
  GameObject rupee;
  rupee.location = LocationComponent(200, 500);
  rupee.sprite =
      SpriteComponent("item_sprite", {.x = 15, .y = 86, .w = 11, .h = 15}, 2);
  std::vector<GameObject> objects = {map, rupee, lonk};
  GraphicsEngine graphics_engine;
  InputEngine input_engine;
  MapEngine map_engine;
  MovementEngine movement_engine;
  while (true) {
    frame_start_time_ms = SDL_GetTicks();
    for (auto &object : objects) {
      if (object.is_map) {
        map_engine.Run(object, graphics_engine);
      } else {
        graphics_engine.Run(object);
      }
      input_engine.Run();
      if (InputComponent::Get().quit) {
        return;
      }
      movement_engine.Run(object);
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
