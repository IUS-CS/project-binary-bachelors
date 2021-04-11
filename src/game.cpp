#include <iostream>
#include <vector>

#include "ai_component.h"
#include "ai_engine.h"
#include "collision_detection_engine.h"
#include "game.h"
#include "graphics_component.h"
#include "graphics_engine.h"
#include "health_engine.h"
#include "hud_engine.h"
#include "input_component.h"
#include "input_engine.h"
#include "map_engine.h"
#include "movement_engine.h"
#include "utils.h"

Game::Game() {}

Game::~Game() {}

void Game::Run() {
  AIEngine ai_engine;
  CollisionDetectionEngine collision_detection_engine;
  GraphicsEngine graphics_engine;
  InputEngine input_engine;
  MapEngine map_engine;
  MovementEngine movement_engine;
  HealthEngine health_engine;
  HudEngine hud_engine;

  GameObject &player = GetPlayer(object_list);

  while (true) {
    frame_start_time_ms = SDL_GetTicks();
    // Gets user input once per frame. That's why it is outside the for loop.
    input_engine.Run();
    if (InputComponent::Get().quit) {
      return;
    }
    int size = object_list.size();
    for (int i = 0; i < size; i++) {
      auto &object = object_list[i];
      if (object.is_active) {
        // At the beginning of the loop, we run all of the engines that will
        // change data inside our game object.
        ai_engine.Run(object, player);
        collision_detection_engine.Run(object, object_list);
        health_engine.Run(object, object_list);
        if (size != (int)object_list.size()) {
          break;
        }
        movement_engine.Run(object);

        // Then we draw the game object to the renderer.
        if (object.type == ObjectType::kMap) {
          map_engine.Run(object, graphics_engine);
        } else if (object.type == ObjectType::kHud) {
          hud_engine.Run(object, graphics_engine, player);
        } else {
          graphics_engine.Run(object);
        }
      }
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
