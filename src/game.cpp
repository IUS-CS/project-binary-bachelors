#include <vector>

#include "collision_detection_engine.h"
#include "game.h"
#include "graphics_component.h"
#include "graphics_engine.h"
#include "input_component.h"
#include "input_engine.h"
#include "map_engine.h"
#include "movement_engine.h"
#include "health_engine.h"

#include <iostream>

Game::Game() {}

Game::~Game() {}

void Game::Run() {
  CollisionDetectionEngine collision_detection_engine;
  GraphicsEngine graphics_engine;
  InputEngine input_engine;
  MapEngine map_engine;
  MovementEngine movement_engine;
  HealthEngine health_engine;

  while (true) {
    frame_start_time_ms = SDL_GetTicks();
    for (auto &object : object_list) {
      if (object.is_active) {
        collision_detection_engine.Run(object, object_list);
        health_engine.Run(object);
        if (object.type == ObjectType::kMap) {
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
