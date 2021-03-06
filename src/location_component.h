#ifndef LOCATION_COMPONENT_H
#define LOCATION_COMPONENT_H

#include "component.h"

class LocationComponent : public Component {
public:
  int x_ = 0;
  int y_ = 100;
};
#endif
