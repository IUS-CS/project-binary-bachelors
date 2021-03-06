#ifndef UTILS_H
#define UTILS_H

// This file will contain useful functions that we can use elsewhere. Nothing
// special.

// Gets a path from a sprite sheet name.
std::string GetAssetPath(const std::string &name) {
  return "assets/" + name + ".png";
};
#endif
