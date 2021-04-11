#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <optional>

#include "ai_component.h"
#include "health_component.h"
#include "hit_box_component.h"
#include "hud_component.h"
#include "location_component.h"
#include "map_component.h"
#include "movement_component.h"
#include "sprite_component.h"

enum struct ObjectType {
  kEnemy,
  kPlayer,
  kGreenRupee,
  kBlueRupee,
  kHeart,
  kMap,
  kHud,
  kAttack,
  kDefault
};

// A GameObject is anything that exists inside the game.
struct GameObject {
public:
  std::optional<SpriteComponent> sprite = std::nullopt;
  std::optional<LocationComponent> location = std::nullopt;
  std::optional<MapComponent> map = std::nullopt;
  std::optional<HitBoxComponent> hit_box = std::nullopt;
  std::optional<HealthComponent> health = std::nullopt;
  std::optional<AIComponent> ai = std::nullopt;
  std::optional<MovementComponent> movement = std::nullopt;
  std::optional<HudComponent> hud = std::nullopt;

  bool is_active = false;
  int id_num;
  ObjectType type = ObjectType::kDefault;
  std::vector<GameObject *> objects_hit;
};
#endif
