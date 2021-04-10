#include "utils.h"
#include <iostream>

std::string GetAssetPath(const std::string &name) {
  return "assets/" + name + ".png";
}

BoundingBox GetBoundingBox(const GameObject &object) {
  // auto [left, top] = object.location->coordinates;
  auto left = object.location->coordinates.x + object.sprite->offset.x;
  auto top = object.location->coordinates.y + object.sprite->offset.y;
  if (object.type == ObjectType::kPlayer) {
    //    std::cout << "x: " << object.sprite->offset.x << std::endl;
    //  std::cout << "y: " << object.sprite->offset.y << std::endl;
  }
  int right = left + object.sprite->sprite_rect.w * object.sprite->scale;
  int bottom = top + object.sprite->sprite_rect.h * object.sprite->scale;
  return {left, right, top, bottom};
}

GameObject &GetPlayer(std::vector<GameObject> &objects) {
  for (auto &object : objects) {
    if (object.type == ObjectType::kPlayer) {
      return object;
    }
  }
}
