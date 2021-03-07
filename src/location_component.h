#ifndef LOCATION_COMPONENT_H
#define LOCATION_COMPONENT_H

#include "component.h"
#include "vector2.h"

// This component is just the coordinates of where the game object is on the
// screen.
class LocationComponent : public Component {
public:
  LocationComponent() { type = ComponentType::kLocation; }

  Vector2 location = Vector2(0, 100);
};
#endif
