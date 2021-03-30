#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "collision_detection_engine.h"
#include "game_object.h"
#include "health_engine.h"
#include "input_component.h"
#include "movement_engine.h"
#include "utils.h"

#include <vector>

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

TEST_CASE("Lonk loses heart", "[lose_heart]") {
  GameObject lonk;
  GameObject enemy;
  lonk.type = ObjectType::kPlayer;
  enemy.type = ObjectType::kEnemy;
  lonk.sprite =
      SpriteComponent("lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3);
  enemy.sprite = SpriteComponent("monster_sprite",
                                 {.x = 16, .y = 13, .w = 16, .h = 19}, 3);
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

