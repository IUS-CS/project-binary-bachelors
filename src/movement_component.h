#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

enum class MovementDirection {
  kUp,
  kDown,
  kLeft,
  kRight,
  kUpRight,
  kUpLeft,
  kDownRight,
  kDownLeft,
  kNone
};

struct MovementComponent {
  MovementComponent() {}
  MovementComponent(int speed) { this->speed = speed; }
  ~MovementComponent() {}
  bool lock_left, lock_right, lock_up, lock_down = false;
  MovementDirection current_direction = MovementDirection::kNone;
  int speed = 1;
};
#endif
