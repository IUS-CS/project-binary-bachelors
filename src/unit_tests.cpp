#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "game_object.h"
#include "input_component.h"
#include "movement_engine.h"

TEST_CASE("Lonk moves to the right", "[move_right]") {
  GameObject rupee;
  GameObject lonk;
  rupee.is_player = false;
  lonk.is_player = true;
  rupee.location = LocationComponent(200, 200);
  lonk.location = LocationComponent(100, 100);
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
  rupee.is_player = false;
  lonk.is_player = true;
  rupee.location = LocationComponent(200, 200);
  lonk.location = LocationComponent(100, 100);
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
  rupee.is_player = false;
  lonk.is_player = true;
  rupee.location = LocationComponent(200, 200);
  lonk.location = LocationComponent(100, 100);
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
  rupee.is_player = false;
  lonk.is_player = true;
  rupee.location = LocationComponent(200, 200);
  lonk.location = LocationComponent(100, 100);
  MovementEngine movement_engine;
  InputComponent::Get().down = true;
  movement_engine.Run(lonk);
  REQUIRE(rupee.location->coordinates.x == 200);
  REQUIRE(rupee.location->coordinates.y == 200);
  REQUIRE(lonk.location->coordinates.x == 100);
  REQUIRE(lonk.location->coordinates.y > 100);
  InputComponent::Get().down = false;
}

