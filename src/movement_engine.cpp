#include "movement_engine.h"
#include "input_component.h"

MovementEngine::MovementEngine() {}

MovementEngine::~MovementEngine() {}

void MovementEngine::Run(GameObject &object) {
  auto &ic = InputComponent::Get();
  if (object.location) {
    if (object.type == ObjectType::kPlayer) {
      if (ic.right) {
        object.location->coordinates.x += 4;
        object.location->direction_faced = Facing::kRight;
      }
      if (ic.left) {
        object.location->coordinates.x -= 4;
        object.location->direction_faced = Facing::kLeft;
      }
      if (ic.up) {
        object.location->coordinates.y -= 4;
        // object.location->direction_faced = Facing::kUp;
      }
      if (ic.down) {
        object.location->coordinates.y += 4;
        // object.location->direction_faced = Facing::kDown;
      }
    }
  }
}
