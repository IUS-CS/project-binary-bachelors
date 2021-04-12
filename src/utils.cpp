#include "utils.h"
#include <iostream>

std::string GetAssetPath(const std::string &name) {
  return "assets/" + name + ".png";
}

BoundingBox GetBoundingBox(const GameObject &object) {
  // auto [left, top] = object.location->coordinates;
  auto left = object.location->coordinates.x + object.sprite->offset.x;
  auto top = object.location->coordinates.y + object.sprite->offset.y;
  int right = left + object.sprite->sprite_rect.w * object.sprite->scale;
  int bottom = top + object.sprite->sprite_rect.h * object.sprite->scale;
  return {left, right, top, bottom};
}

HitBox GetHitBox(const GameObject &object) {
  // auto [left, top] = object.location->coordinates;
  int left;
  int right;
  int top;
  int bottom;
  if (object.type == ObjectType::kPlayer) {
    // Need to be changed
    left = object.hit_box->hit_box.x + object.sprite->offset.x;
    top = object.hit_box->hit_box.y + object.sprite->offset.y;
    right = left + object.hit_box->hit_box.w;
    bottom = top + object.hit_box->hit_box.h;
  } else {
    left = object.location->coordinates.x + object.sprite->offset.x;
    top = object.location->coordinates.y + object.sprite->offset.y;
    right = left + object.sprite->sprite_rect.w * object.sprite->scale;
    bottom = top + object.sprite->sprite_rect.h * object.sprite->scale;
  }
  return {left, right, top, bottom};
}

GameObject &GetPlayer(std::vector<GameObject> &objects) {
  for (auto &object : objects) {
    if (object.type == ObjectType::kPlayer) {
      return object;
    }
  }
}
