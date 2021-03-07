#ifndef COMPONENT_H
#define COMPONENT_H

enum class ComponentType { kSprite, kLocation };
// This seems like an unnecessary file but it is actual very important. In order
// to add all of the components into a vector together, they need to either be
// the same type, or we would have to use generic typing. With this file, we
// just make other components extend this file. That way, we can easily add them
// to the same vector.
class Component {
public:
  ComponentType type;
};
#endif
