#define CATCH_CONFIG_MAIN
#include "ai_component.h"
#include "ai_engine.h"
#include "animation_engine.h"
#include "catch_amalgamated.hpp"
#include "collision_detection_engine.h"
#include "data/lonk.h"
#include "data/orc.h"
#include "game_object.h"
#include "health_engine.h"
#include "input_component.h"
#include "movement_engine.h"
#include "utils.h"
#include <iostream>
#include <vector>

TEST_CASE("Test Collision Detection", "[collision_detection]") {
  Lonk lonk_data;
  GameObject lonk = lonk_data.LoadLonk({200, 200});
  Orc orc_data;
  GameObject orc = orc_data.LoadOrc({200, 200});
  lonk.id_num = 1;
  orc.id_num = 0;
  std::vector<GameObject> objects = {lonk, orc};
  CollisionDetectionEngine collision_detection_engine;
  collision_detection_engine.Run(lonk, objects);
  REQUIRE(lonk.objects_hit.size() == 1);
}

TEST_CASE("Lonk moves to the right", "[move_right]") {
  Lonk lonk_data;
  GameObject lonk = lonk_data.LoadLonk({100, 100});
  MovementEngine movement_engine;
  InputComponent::Get().right = true;
  movement_engine.Run(lonk);
  REQUIRE(lonk.location->coordinates.x > 100);
  REQUIRE(lonk.location->coordinates.y == 100);
  InputComponent::Get().right = false;
}

TEST_CASE("Lonk moves to the left", "[move_left]") {
  Lonk lonk_data;
  GameObject lonk = lonk_data.LoadLonk({100, 100});
  MovementEngine movement_engine;
  InputComponent::Get().left = true;
  movement_engine.Run(lonk);
  REQUIRE(lonk.location->coordinates.x < 100);
  REQUIRE(lonk.location->coordinates.y == 100);
  InputComponent::Get().left = false;
}

TEST_CASE("Lonk moves up", "[move_up]") {
  Lonk lonk_data;
  GameObject lonk = lonk_data.LoadLonk({100, 100});
  MovementEngine movement_engine;
  InputComponent::Get().up = true;
  movement_engine.Run(lonk);
  REQUIRE(lonk.location->coordinates.x == 100);
  REQUIRE(lonk.location->coordinates.y < 100);
  InputComponent::Get().up = false;
}

TEST_CASE("Lonk moves down", "[move_down]") {
  Lonk lonk_data;
  GameObject lonk = lonk_data.LoadLonk({100, 100});
  MovementEngine movement_engine;
  InputComponent::Get().down = true;
  movement_engine.Run(lonk);
  REQUIRE(lonk.location->coordinates.x == 100);
  REQUIRE(lonk.location->coordinates.y > 100);
  InputComponent::Get().down = false;
}

TEST_CASE("AI move left", "[ai_left]") {
  Lonk lonk_data;
  GameObject lonk = lonk_data.LoadLonk({100, 200});
  Orc orc_data;
  GameObject orc = orc_data.LoadOrc({300, 200});
  AIEngine ai_engine;
  MovementEngine movement_engine;
  ai_engine.ChasePlayer(orc, lonk);
  movement_engine.Run(orc);
  REQUIRE(orc.location->coordinates.x < 300);
}

TEST_CASE("AI move right", "[ai_right]") {
  Lonk lonk_data;
  GameObject lonk = lonk_data.LoadLonk({300, 200});
  Orc orc_data;
  GameObject orc = orc_data.LoadOrc({100, 200});
  AIEngine ai_engine;
  MovementEngine movement_engine;
  ai_engine.ChasePlayer(orc, lonk);
  movement_engine.Run(orc);
  REQUIRE(orc.location->coordinates.x > 100);
}

TEST_CASE("AI move up", "[ai_up]") {
  Lonk lonk_data;
  GameObject lonk = lonk_data.LoadLonk({200, 100});
  Orc orc_data;
  GameObject orc = orc_data.LoadOrc({200, 300});
  AIEngine ai_engine;
  MovementEngine movement_engine;
  ai_engine.ChasePlayer(orc, lonk);
  movement_engine.Run(orc);
  REQUIRE(orc.location->coordinates.y < 300);
}

TEST_CASE("AI move down", "[ai_down]") {
  Lonk lonk_data;
  GameObject lonk = lonk_data.LoadLonk({200, 300});
  Orc orc_data;
  GameObject orc = orc_data.LoadOrc({200, 100});
  AIEngine ai_engine;
  MovementEngine movement_engine;
  ai_engine.ChasePlayer(orc, lonk);
  std::cout << orc.location->coordinates.y << std::endl;
  movement_engine.Run(orc);
  REQUIRE(orc.location->coordinates.y > 100);
}

TEST_CASE("Lonk loses heart", "[lose_heart]") {
  std::vector<GameObject> objects_to_add;
  GameObject lonk;
  GameObject enemy;
  lonk.type = ObjectType::kPlayer;
  enemy.type = ObjectType::kEnemy;
  lonk.sprite = SpriteComponent(
      "lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3, {0, 0});
  enemy.sprite = SpriteComponent(
      "monster_sprite", {.x = 16, .y = 13, .w = 16, .h = 19}, 3, {0, 0});
  LonkAnimations a_lonk;
  lonk.animation = AnimationComponent(a_lonk.animations);
  lonk.hit_box = HitBoxComponent();
  enemy.hit_box = HitBoxComponent();
  lonk.is_active = true;
  enemy.is_active = true;
  lonk.health = HealthComponent(3);
  lonk.location = LocationComponent(100, 100);
  enemy.location = LocationComponent(100, 100);
  std::vector<GameObject> objects = {lonk, enemy};
  CollisionDetectionEngine collision_detection_engine;
  HealthEngine health_engine;
  collision_detection_engine.Run(lonk, objects);
  health_engine.Run(lonk, objects_to_add);
  REQUIRE(lonk.health->health == 2);
}

TEST_CASE("AI move up_left", "[ai_up_left]") {
  GameObject lonk;
  GameObject enemy;
  AIEngine ai_engine;
  MovementEngine movement_engine;
  lonk.type = ObjectType::kPlayer;
  enemy.type = ObjectType::kEnemy;
  OrcAnimations a_orc;
  enemy.animation = AnimationComponent(a_orc.animations);
  enemy.is_active = true;
  lonk.sprite = SpriteComponent(
      "lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3, {0, 0});
  enemy.sprite = SpriteComponent(
      "monster_sprite", {.x = 16, .y = 13, .w = 16, .h = 19}, 3, {0, 0});
  lonk.location = LocationComponent(200, 100);
  enemy.location = LocationComponent(300, 200);
  enemy.ai = AIComponent();
  enemy.movement = MovementComponent(5);
  ai_engine.ChasePlayer(enemy, lonk);
  movement_engine.Run(enemy);
  REQUIRE(enemy.location->coordinates.x < 300);
  REQUIRE(enemy.location->coordinates.y < 200);
}

TEST_CASE("AI move down_left", "[ai_down_left]") {
  GameObject lonk;
  GameObject enemy;
  AIEngine ai_engine;
  MovementEngine movement_engine;
  lonk.type = ObjectType::kPlayer;
  enemy.type = ObjectType::kEnemy;
  OrcAnimations a_orc;
  enemy.animation = AnimationComponent(a_orc.animations);
  enemy.is_active = true;
  lonk.sprite = SpriteComponent(
      "lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3, {0, 0});
  enemy.sprite = SpriteComponent(
      "monster_sprite", {.x = 16, .y = 13, .w = 16, .h = 19}, 3, {0, 0});
  lonk.location = LocationComponent(200, 300);
  enemy.location = LocationComponent(300, 200);
  enemy.ai = AIComponent();
  enemy.movement = MovementComponent(5);
  ai_engine.ChasePlayer(enemy, lonk);
  movement_engine.Run(enemy);
  REQUIRE(enemy.location->coordinates.x < 300);
  REQUIRE(enemy.location->coordinates.y > 200);
}

TEST_CASE("AI move up_right", "[ai_up_right]") {
  GameObject lonk;
  GameObject enemy;
  AIEngine ai_engine;
  MovementEngine movement_engine;
  lonk.type = ObjectType::kPlayer;
  enemy.type = ObjectType::kEnemy;
  OrcAnimations a_orc;
  enemy.animation = AnimationComponent(a_orc.animations);
  enemy.is_active = true;
  lonk.sprite = SpriteComponent(
      "lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3, {0, 0});
  enemy.sprite = SpriteComponent(
      "monster_sprite", {.x = 16, .y = 13, .w = 16, .h = 19}, 3, {0, 0});
  lonk.location = LocationComponent(400, 100);
  enemy.location = LocationComponent(300, 200);
  enemy.ai = AIComponent();
  enemy.movement = MovementComponent(5);
  ai_engine.ChasePlayer(enemy, lonk);
  movement_engine.Run(enemy);
  REQUIRE(enemy.location->coordinates.x > 300);
  REQUIRE(enemy.location->coordinates.y < 200);
}

TEST_CASE("AI move down_right", "[ai_down_right]") {
  GameObject lonk;
  GameObject enemy;
  AIEngine ai_engine;
  MovementEngine movement_engine;
  lonk.type = ObjectType::kPlayer;
  enemy.type = ObjectType::kEnemy;
  OrcAnimations a_orc;
  enemy.animation = AnimationComponent(a_orc.animations);
  enemy.is_active = true;
  lonk.sprite = SpriteComponent(
      "lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3, {0, 0});
  enemy.sprite = SpriteComponent(
      "monster_sprite", {.x = 16, .y = 13, .w = 16, .h = 19}, 3, {0, 0});
  lonk.location = LocationComponent(400, 300);
  enemy.location = LocationComponent(300, 200);
  enemy.ai = AIComponent();
  enemy.movement = MovementComponent(5);
  ai_engine.ChasePlayer(enemy, lonk);
  movement_engine.Run(enemy);
  REQUIRE(enemy.location->coordinates.x > 300);
  REQUIRE(enemy.location->coordinates.y > 200);
}
