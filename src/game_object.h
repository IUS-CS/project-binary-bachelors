#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "component.h"
#include <vector>

// A GameObject is anything that exists inside the game.
class GameObject {
public:
  GameObject();
  ~GameObject();

  // This will add a component to the component list for this GameObject.
  void AddComponent(Component component);

  // This is a vector containing all of the components that this GameObject has.
  std::vector<Component> component_list;
};
#endif
