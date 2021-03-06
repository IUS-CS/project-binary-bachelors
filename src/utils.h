#ifndef UTILS_H
#define UTILS_H
// Gets a path from a sprite sheet name.
std::string GetAssetPath(const std::string &name) {
  return "assets/" + name + ".png";
};
#endif
