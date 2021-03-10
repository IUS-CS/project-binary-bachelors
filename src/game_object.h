#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <optional>

#include "location_component.h"
#include "map_component.h"
#include "sprite_component.h"

// A GameObject is anything that exists inside the game.
struct GameObject {
public:
  std::optional<SpriteComponent> sprite = std::nullopt;
  std::optional<LocationComponent> location = std::nullopt;
  std::optional<MapComponent> map = std::nullopt;

  bool is_map = false;
  bool is_player = false;
};
#endif
