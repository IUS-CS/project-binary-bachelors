#ifndef UTILS_H
#define UTILS_H

#include "game_object.h"

// This file will contain useful functions that we can use elsewhere. Nothing
// special.

struct BoundingBox {
  int left;
  int right;
  int top;
  int bottom;
};

// Gets a path from a sprite sheet name.
std::string GetAssetPath(const std::string &name);

BoundingBox GetBoundingBox(const GameObject &object);

#endif
