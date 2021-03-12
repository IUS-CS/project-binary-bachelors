#include "utils.h"

std::string GetAssetPath(const std::string &name) {
  return "assets/" + name + ".png";
}

BoundingBox GetBoundingBox(const GameObject &object) {
  auto [left, top] = object.location->coordinates;
  int right = left + object.sprite->sprite_rect.w * object.sprite->scale;
  int bottom = top + object.sprite->sprite_rect.h * object.sprite->scale;
  return {left, right, top, bottom};
}

