#include "game_object.h"

GameObject::GameObject() {}
GameObject::~GameObject() {}
void GameObject::Update() {
  for (unsigned int i = 0; i < component_list_.size(); i++) {
    // component_list_[i].Update();
  }
}
void GameObject::AddComponent(Component component) {
  component_list_.push_back(component);
}
