#ifndef LOCATION_COMPONENT_H
#define LOCATION_COMPONENT_H

#include "component.h"

// This component is just the coordinates of where the game object is on the
// screen.
class LocationComponent : public Component {
public:
  int x_ = 0;
  int y_ = 100;
};
#endif
