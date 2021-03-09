#include "movement_engine.h"
#include "input_component.h"

MovementEngine::MovementEngine() {}

MovementEngine::~MovementEngine() {}

void MovementEngine::Run(GameObject &object) {
  auto &ic = InputComponent::Get();
  if (object.location) {
    if (object.is_player) {
      if (ic.right) {
        object.location->coordinates.x += 4;
      }
      if (ic.left) {
        object.location->coordinates.x -= 4;
      }
      if (ic.up) {
        object.location->coordinates.y -= 4;
      }
      if (ic.down) {
        object.location->coordinates.y += 4;
      }
    }
  }
}
