#ifndef AI_COMPONENT_H
#define AI_COMPONENT_H

#include <SDL2/SDL.h>

enum class ActionType { kCutOffPlayer, kChase, kAttackPlayer, kDefault };

struct AIComponent {
  AIComponent() {
    time_of_last_decision_ms = 0;
    current_action = ActionType::kDefault;
  }
  AIComponent(SDL_Rect hit) {}
  ~AIComponent() {}

  bool in_attack_range = false;
  SDL_Rect attack;
  int time_of_last_decision_ms;
  ActionType current_action;
};

#endif
