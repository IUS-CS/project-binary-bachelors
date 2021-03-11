#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <optional>

#include "hit_box_component.h"
#include "location_component.h"
#include "map_component.h"
#include "sprite_component.h"

enum struct ObjectType { kPlayer, kMap, kDefault };

// A GameObject is anything that exists inside the game.
struct GameObject {
public:
  std::optional<SpriteComponent> sprite = std::nullopt;
  std::optional<LocationComponent> location = std::nullopt;
  std::optional<MapComponent> map = std::nullopt;
  std::optional<HitBoxComponent> hit_box = std::nullopt;

  ObjectType type = ObjectType::kDefault;
};
#endif
