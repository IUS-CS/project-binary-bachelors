#ifndef LOCATION_COMPONENT_H
#define LOCATION_COMPONENT_H

#include "vector2.h"

enum class DirectionFaced { kUp, kDown, kLeft, kRight };

// This component is just the coordinates of where the game object is on the
// screen.
struct LocationComponent {
  LocationComponent() {
    coordinates.x = 0;
    coordinates.y = 0;
  }
  LocationComponent(int x, int y) {
    coordinates.x = x;
    coordinates.y = y;
  }
  DirectionFaced direction_faced = DirectionFaced::kDown;
  bool flip = false;
  Vector2 coordinates;
};
#endif
