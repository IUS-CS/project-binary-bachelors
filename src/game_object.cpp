#include "game_object.h"

GameObject::GameObject() {}
GameObject::~GameObject() {}

void GameObject::AddComponent(Component component) {
  component_list.push_back(component);
}
