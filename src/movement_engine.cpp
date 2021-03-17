#include "movement_engine.h"
#include "input_component.h"
#include "utils.h"

#include <iostream>

MovementEngine::MovementEngine() {}

MovementEngine::~MovementEngine() {}

void MovementEngine::Run(GameObject &object) {
  object.movement->lock_left = false;
  object.movement->lock_right = false;
  object.movement->lock_down = false;
  object.movement->lock_up = false;
  if (object.type == ObjectType::kPlayer) {
    object.movement->current_direction = MovementDirection::kNone;
  }
  for (auto &obstacle : object.objects_hit) {
    if (obstacle->type == ObjectType::kEnemy &&
        object.type == ObjectType::kEnemy) {
      BoundingBox object_box = GetBoundingBox(object);
      BoundingBox obstacle_box = GetBoundingBox(*obstacle);
      if (object_box.left <
              obstacle_box.right - (obstacle->sprite->sprite_rect.w *
                                    obstacle->sprite->scale / 2) &&
          object_box.left > obstacle_box.left) {
        object.movement->lock_left = true;
      }
      if (object_box.right >
              obstacle_box.left + (obstacle->sprite->sprite_rect.w *
                                   obstacle->sprite->scale / 2) &&
          object_box.right < obstacle_box.right) {
        object.movement->lock_right = true;
      }
      if (!object.movement->lock_right && !object.movement->lock_left) {
        if (object_box.bottom >
                obstacle_box.top + (obstacle->sprite->sprite_rect.h *
                                    obstacle->sprite->scale / 2) &&
            object_box.bottom < obstacle_box.bottom) {
          object.movement->lock_down = true;
        }
        if (object_box.top <
                obstacle_box.bottom - (obstacle->sprite->sprite_rect.h *
                                       obstacle->sprite->scale / 2) &&
            object_box.top > obstacle_box.top) {

          object.movement->lock_up = true;
        }
      }
    }
  }

  auto &ic = InputComponent::Get();
  if (object.location && object.movement) {
    if (object.type == ObjectType::kPlayer) {
      if (ic.up) {
        object.movement->current_direction = MovementDirection::kUp;
      } else if (ic.down) {
        object.movement->current_direction = MovementDirection::kDown;
      }
      if (ic.right) {
        object.movement->current_direction = MovementDirection::kRight;
        if (ic.up) {
          object.movement->current_direction = MovementDirection::kUpRight;
        } else if (ic.down) {
          object.movement->current_direction = MovementDirection::kDownRight;
        }
      } else if (ic.left) {
        object.movement->current_direction = MovementDirection::kLeft;
        if (ic.up) {
          object.movement->current_direction = MovementDirection::kUpLeft;
        } else if (ic.down) {
          object.movement->current_direction = MovementDirection::kDownLeft;
        }
      }
      if (object.movement->current_direction == MovementDirection::kRight ||
          object.movement->current_direction == MovementDirection::kUpRight ||
          object.movement->current_direction == MovementDirection::kDownRight) {
        object.location->flip = false;
      }
      if (object.movement->current_direction == MovementDirection::kLeft ||
          object.movement->current_direction == MovementDirection::kUpLeft ||
          object.movement->current_direction == MovementDirection::kDownLeft) {
        object.location->flip = true;
      }
    }

    if (object.movement->current_direction == MovementDirection::kLeft) {
      if (!object.movement->lock_left) {
        object.location->coordinates.x =
            object.location->coordinates.x - object.movement->speed;
      }
    }
    if (object.movement->current_direction == MovementDirection::kRight) {
      if (!object.movement->lock_right) {
        object.location->coordinates.x =
            object.location->coordinates.x + object.movement->speed;
      }
    }
    if (object.movement->current_direction == MovementDirection::kDown) {
      if (!object.movement->lock_down) {
        object.location->coordinates.y =
            object.location->coordinates.y + object.movement->speed;
      }
    }
    if (object.movement->current_direction == MovementDirection::kUp) {
      if (!object.movement->lock_up) {
        object.location->coordinates.y =
            object.location->coordinates.y - object.movement->speed;
      }
    }
    if (object.movement->current_direction == MovementDirection::kUpRight) {
      if (!object.movement->lock_right) {
        object.location->coordinates.x =
            object.location->coordinates.x + object.movement->speed;
      }
      if (!object.movement->lock_up) {
        object.location->coordinates.y =
            object.location->coordinates.y - object.movement->speed;
      }
    }
    if (object.movement->current_direction == MovementDirection::kUpLeft) {
      if (!object.movement->lock_left) {
        object.location->coordinates.x =
            object.location->coordinates.x - object.movement->speed;
      }
      if (!object.movement->lock_up) {
        object.location->coordinates.y =
            object.location->coordinates.y - object.movement->speed;
      }
    }
    if (object.movement->current_direction == MovementDirection::kDownRight) {
      if (!object.movement->lock_right) {
        object.location->coordinates.x =
            object.location->coordinates.x + object.movement->speed;
      }
      if (!object.movement->lock_down) {
        object.location->coordinates.y =
            object.location->coordinates.y + object.movement->speed;
      }
    }
    if (object.movement->current_direction == MovementDirection::kDownLeft) {
      if (!object.movement->lock_left) {
        object.location->coordinates.x =
            object.location->coordinates.x - object.movement->speed;
      }
      if (!object.movement->lock_down) {
        object.location->coordinates.y =
            object.location->coordinates.y + object.movement->speed;
      }
    }
    if (object.type == ObjectType::kEnemy) {
      if (object.movement->current_direction == MovementDirection::kRight ||
          object.movement->current_direction == MovementDirection::kUpRight ||
          object.movement->current_direction == MovementDirection::kDownRight) {
        object.location->flip = true;
      }
      if (object.movement->current_direction == MovementDirection::kLeft ||
          object.movement->current_direction == MovementDirection::kUpLeft ||
          object.movement->current_direction == MovementDirection::kDownLeft) {
        object.location->flip = false;
      }
    }
  }
}
