#include <iostream>
#include <vector>

#include "ai_component.h"
#include "ai_engine.h"
#include "animation_engine.h"
#include "audio.h"
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
#include "wallet_engine.h"

Game::Game() {}

Game::~Game() {}

void Game::Run() {
  SDL_Init(SDL_INIT_EVERYTHING);
  AIEngine ai_engine;
  AnimationEngine animation_engine;
  CollisionDetectionEngine collision_detection_engine;
  GraphicsEngine graphics_engine;
  InputEngine input_engine;
  MapEngine map_engine;
  MovementEngine movement_engine;
  HealthEngine health_engine;
  HudEngine hud_engine;
  WalletEngine wallet_engine;

  Mix_Init(MIX_INIT_MP3);
  std::cout << "Breaking???" << std::endl;
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    std::cout << "RUH ROH RAGGY!" << std::endl;
  }
  Audio sound;
  sound.Play();

  std::vector<GameObject> objects_to_add;

  while (true) {
    GameObject &player = GetPlayer(object_list);
    objects_to_add.clear();
    frame_start_time_ms = SDL_GetTicks();
    // Gets user input once per frame. That's why it is outside the for loop.
    input_engine.Run();
    if (InputComponent::Get().quit) {
      return;
    }
    if (!InputComponent::Get().pause) {
      for (auto &object : object_list) {
        if (object.is_active) {
          // At the beginning of the loop, we run all of the engines that will
          // change data inside our game object.
          ai_engine.Run(object, player);
          collision_detection_engine.Run(object, object_list);
          health_engine.Run(object, objects_to_add);
          animation_engine.Run(object);
          movement_engine.Run(object);
          wallet_engine.Run(object);

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
      for (auto &object : objects_to_add) {
        object_list.push_back(object);
      }
      graphics_engine.DrawNextFrame();
      LimitFrameRate();
    }
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
