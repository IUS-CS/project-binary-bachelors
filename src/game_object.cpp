#include "game_object.h"

GameObject::GameObject() {}
GameObject::~GameObject() {}

void GameObject::AddComponent(Component component) {
  component_list_.push_back(component);
}
