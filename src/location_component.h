#ifndef LOCATION_COMPONENT_H
#define LOCATION_COMPONENT_H

#include "vector2.h"

// This component is just the coordinates of where the game object is on the
// screen.
enum class Facing { kUp, kDown, kLeft, kRight };
struct LocationComponent {
  LocationComponent() {
    coordinates.x = 0;
    coordinates.y = 0;
  }
  LocationComponent(int x, int y) {
    coordinates.x = x;
    coordinates.y = y;
  }
  Facing direction_faced = Facing::kRight;
  Vector2 coordinates;
};
#endif
