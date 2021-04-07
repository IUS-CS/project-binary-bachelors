#define CATCH_CONFIG_MAIN
#include "ai_component.h"
#include "ai_engine.h"
#include "catch_amalgamated.hpp"
#include "collision_detection_engine.h"
#include "game_object.h"
#include "health_engine.h"
#include "input_component.h"
#include "movement_engine.h"
#include "utils.h"
#include <iostream>
#include <vector>

TEST_CASE("Test Collision Detection", "[collision_detection]") {
  GameObject lonk;
  GameObject enemy;
  lonk.type = ObjectType::kPlayer;
  enemy.type = ObjectType::kEnemy;
  lonk.id_num = 1;
  enemy.id_num = 0;
  lonk.is_active = true;
  enemy.is_active = true;
  lonk.sprite = SpriteComponent(
      "lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3, {0, 0});
  enemy.sprite = SpriteComponent(
      "monster_sprite", {.x = 16, .y = 13, .w = 16, .h = 19}, 3, {0, 0});
  lonk.location = LocationComponent(200, 200);
  enemy.location = LocationComponent(200, 200);
  lonk.hit_box = HitBoxComponent();
  enemy.hit_box = HitBoxComponent();
  std::vector<GameObject> objects = {lonk, enemy};
  CollisionDetectionEngine collision_detection_engine;
  collision_detection_engine.Run(lonk, objects);
  REQUIRE(lonk.objects_hit.size() == 1);
}

TEST_CASE("Lonk moves to the right", "[move_right]") {
  GameObject rupee;
  GameObject lonk;
  lonk.type = ObjectType::kPlayer;
  rupee.location = LocationComponent(200, 200);
  lonk.location = LocationComponent(100, 100);
  lonk.movement = MovementComponent(4);
  MovementEngine movement_engine;
  InputComponent::Get().right = true;
  movement_engine.Run(lonk);
  REQUIRE(rupee.location->coordinates.x == 200);
  REQUIRE(rupee.location->coordinates.y == 200);
  REQUIRE(lonk.location->coordinates.x > 100);
  REQUIRE(lonk.location->coordinates.y == 100);
  InputComponent::Get().right = false;
}

TEST_CASE("Lonk moves to the left", "[move_left]") {
  GameObject rupee;
  GameObject lonk;
  lonk.type = ObjectType::kPlayer;
  rupee.location = LocationComponent(200, 200);
  lonk.location = LocationComponent(100, 100);
  lonk.movement = MovementComponent(4);
  MovementEngine movement_engine;
  InputComponent::Get().left = true;
  movement_engine.Run(lonk);
  REQUIRE(rupee.location->coordinates.x == 200);
  REQUIRE(rupee.location->coordinates.y == 200);
  REQUIRE(lonk.location->coordinates.x < 100);
  REQUIRE(lonk.location->coordinates.y == 100);
  InputComponent::Get().left = false;
}

TEST_CASE("Lonk moves up", "[move_up]") {
  GameObject rupee;
  GameObject lonk;
  lonk.type = ObjectType::kPlayer;
  rupee.location = LocationComponent(200, 200);
  lonk.location = LocationComponent(100, 100);
  lonk.movement = MovementComponent(4);
  MovementEngine movement_engine;
  InputComponent::Get().up = true;
  movement_engine.Run(lonk);
  REQUIRE(rupee.location->coordinates.x == 200);
  REQUIRE(rupee.location->coordinates.y == 200);
  REQUIRE(lonk.location->coordinates.x == 100);
  REQUIRE(lonk.location->coordinates.y < 100);
  InputComponent::Get().up = false;
}

TEST_CASE("Lonk moves down", "[move_down]") {
  GameObject rupee;
  GameObject lonk;
  lonk.type = ObjectType::kPlayer;
  rupee.location = LocationComponent(200, 200);
  lonk.location = LocationComponent(100, 100);
  lonk.movement = MovementComponent(4);
  MovementEngine movement_engine;
  InputComponent::Get().down = true;
  movement_engine.Run(lonk);
  REQUIRE(rupee.location->coordinates.x == 200);
  REQUIRE(rupee.location->coordinates.y == 200);
  REQUIRE(lonk.location->coordinates.x == 100);
  REQUIRE(lonk.location->coordinates.y > 100);
  InputComponent::Get().down = false;
}

TEST_CASE("AI move left", "[ai_left]") {
  GameObject lonk;
  GameObject enemy;
  AIEngine ai_engine;
  MovementEngine movement_engine;
  lonk.type = ObjectType::kPlayer;
  enemy.type = ObjectType::kEnemy;
  enemy.is_active = true;
  lonk.sprite = SpriteComponent(
      "lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3, {0, 0});
  enemy.sprite = SpriteComponent(
      "monster_sprite", {.x = 16, .y = 13, .w = 16, .h = 19}, 3, {0, 0});
  lonk.location = LocationComponent(200, 200);
  enemy.location = LocationComponent(300, 200);
  enemy.ai = AIComponent();
  enemy.movement = MovementComponent(5);
  ai_engine.ChasePlayer(enemy, lonk);
  movement_engine.Run(enemy);
  REQUIRE(enemy.location->coordinates.x < 300);
}

TEST_CASE("AI move right", "[ai_right]") {
  GameObject lonk;
  GameObject enemy;
  AIEngine ai_engine;
  MovementEngine movement_engine;
  lonk.type = ObjectType::kPlayer;
  enemy.type = ObjectType::kEnemy;
  enemy.is_active = true;
  lonk.sprite = SpriteComponent(
      "lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3, {0, 0});
  enemy.sprite = SpriteComponent(
      "monster_sprite", {.x = 16, .y = 13, .w = 16, .h = 19}, 3, {0, 0});
  lonk.location = LocationComponent(200, 200);
  enemy.location = LocationComponent(100, 200);
  enemy.ai = AIComponent();
  enemy.movement = MovementComponent(5);
  ai_engine.ChasePlayer(enemy, lonk);
  movement_engine.Run(enemy);
  REQUIRE(enemy.location->coordinates.x > 100);
}

TEST_CASE("AI move up", "[ai_up]") {
  GameObject lonk;
  GameObject enemy;
  AIEngine ai_engine;
  MovementEngine movement_engine;
  lonk.type = ObjectType::kPlayer;
  enemy.type = ObjectType::kEnemy;
  enemy.is_active = true;
  lonk.sprite = SpriteComponent(
      "lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3, {0, 0});
  enemy.sprite = SpriteComponent(
      "monster_sprite", {.x = 16, .y = 13, .w = 16, .h = 19}, 3, {0, 0});
  lonk.location = LocationComponent(200, 200);
  enemy.location = LocationComponent(200, 100);
  enemy.ai = AIComponent();
  enemy.movement = MovementComponent(5);
  ai_engine.ChasePlayer(enemy, lonk);
  movement_engine.Run(enemy);
  REQUIRE(enemy.location->coordinates.y > 100);
}

TEST_CASE("AI move down", "[ai_down]") {
  GameObject lonk;
  GameObject enemy;
  AIEngine ai_engine;
  MovementEngine movement_engine;
  lonk.type = ObjectType::kPlayer;
  enemy.type = ObjectType::kEnemy;
  enemy.is_active = true;
  lonk.sprite = SpriteComponent(
      "lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3, {0, 0});
  enemy.sprite = SpriteComponent(
      "monster_sprite", {.x = 16, .y = 13, .w = 16, .h = 19}, 3, {0, 0});
  lonk.location = LocationComponent(200, 200);
  enemy.location = LocationComponent(200, 300);
  enemy.ai = AIComponent();
  enemy.movement = MovementComponent(5);
  ai_engine.ChasePlayer(enemy, lonk);
  movement_engine.Run(enemy);
  REQUIRE(enemy.location->coordinates.y < 300);
}

TEST_CASE("Lonk loses heart", "[lose_heart]") {
  GameObject lonk;
  GameObject enemy;
  lonk.type = ObjectType::kPlayer;
  enemy.type = ObjectType::kEnemy;
  lonk.sprite = SpriteComponent(
      "lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3, {0, 0});
  enemy.sprite = SpriteComponent(
      "monster_sprite", {.x = 16, .y = 13, .w = 16, .h = 19}, 3, {0, 0});
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
  health_engine.Run(lonk);
  REQUIRE(lonk.health->health == 2);
}

TEST_CASE("AI move up_left", "[ai_up_left]") {
  GameObject lonk;
  GameObject enemy;
  AIEngine ai_engine;
  MovementEngine movement_engine;
  lonk.type = ObjectType::kPlayer;
  enemy.type = ObjectType::kEnemy;
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
