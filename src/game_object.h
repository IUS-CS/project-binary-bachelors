#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "component.h"
#include <vector>

class GameObject {
public:
  GameObject();
  ~GameObject();
  void Update();
  void AddComponent(Component component);

  std::vector<Component> component_list_;
};
#endif
