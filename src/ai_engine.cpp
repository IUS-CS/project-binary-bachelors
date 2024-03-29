#include "ai_engine.h"
#include "utils.h"
#include <random>

#include <iostream>
AIEngine::AIEngine() {}

AIEngine::~AIEngine() {}

void AIEngine::Run(GameObject &object, GameObject &player) {
  if (object.ai) {
    object.movement->current_direction = MovementDirection::kNone;
    InAttackRangeCheck(object, player);
    std::random_device generator;
    std::mt19937 mt(generator());
    std::uniform_int_distribution<int> distribution(0, 500);
    int random_num = distribution(generator);
    if (object.ai->in_attack_range == true &&
        SDL_GetTicks() - object.ai->entered_attack_range_ms >
            (unsigned)(300 + random_num)) {
      NextMove(object);
    } else if (TimeForNewDecision(object)) {
      NextMove(object);
    }
    if (object.ai->current_action == ActionType::kDefault) {
    }
    if (object.ai->current_action == ActionType::kChase) {
      ChasePlayer(object, player);
    }
    if (object.ai->current_action == ActionType::kCutOffPlayer) {
      CutOffPlayer(object, player);
    }
  }
}

void AIEngine::CutOffPlayer(GameObject &object, GameObject &player) {
  if (object.movement) {
    ChasePlayer(object, player);
    if (object.movement->current_direction == MovementDirection::kUpLeft &&
        (player.movement->current_direction == MovementDirection::kRight ||
         player.movement->current_direction == MovementDirection::kUpRight)) {
      object.movement->current_direction = MovementDirection::kUp;
    } else if (object.movement->current_direction ==
                   MovementDirection::kUpLeft &&
               (player.movement->current_direction ==
                    MovementDirection::kDown ||
                player.movement->current_direction ==
                    MovementDirection::kDownLeft)) {
      object.movement->current_direction = MovementDirection::kLeft;
    } else if (object.movement->current_direction ==
                   MovementDirection::kUpRight &&
               (player.movement->current_direction ==
                    MovementDirection::kDown ||
                player.movement->current_direction ==
                    MovementDirection::kDownRight)) {
      object.movement->current_direction = MovementDirection::kRight;
    } else if (object.movement->current_direction ==
                   MovementDirection::kUpRight &&
               (player.movement->current_direction ==
                    MovementDirection::kLeft ||
                player.movement->current_direction ==
                    MovementDirection::kUpLeft)) {
      object.movement->current_direction = MovementDirection::kUp;
    } else if (object.movement->current_direction ==
                   MovementDirection::kDownLeft &&
               (player.movement->current_direction == MovementDirection::kUp ||
                player.movement->current_direction ==
                    MovementDirection::kUpLeft)) {
      object.movement->current_direction = MovementDirection::kLeft;
    } else if (object.movement->current_direction ==
                   MovementDirection::kDownLeft &&
               (player.movement->current_direction ==
                    MovementDirection::kRight ||
                player.movement->current_direction ==
                    MovementDirection::kDownRight)) {
      object.movement->current_direction = MovementDirection::kDown;
    } else if (object.movement->current_direction ==
                   MovementDirection::kDownRight &&
               (player.movement->current_direction == MovementDirection::kUp ||
                player.movement->current_direction ==
                    MovementDirection::kUpRight)) {
      object.movement->current_direction = MovementDirection::kRight;
    } else if (object.movement->current_direction ==
                   MovementDirection::kDownRight &&
               (player.movement->current_direction ==
                    MovementDirection::kLeft ||
                player.movement->current_direction ==
                    MovementDirection::kUpLeft)) {
      object.movement->current_direction = MovementDirection::kDown;
    }
  }
}

void AIEngine::ChasePlayer(GameObject &object, GameObject &player) {
  if (object.movement) {
    object.movement->current_direction = MovementDirection::kNone;
    HitBox player_box = GetHitBox(player);
    BoundingBox enemy_box = GetBoundingBox(object);
    if (enemy_box.left > player_box.right + 15) {
      object.movement->current_direction = MovementDirection::kLeft;
    } else if (enemy_box.right < player_box.left - 15) {
      object.movement->current_direction = MovementDirection::kRight;
    }
    if (enemy_box.bottom < player_box.top + 15) {
      object.movement->current_direction = MovementDirection::kDown;
    } else if (enemy_box.top > player_box.bottom - 15) {
      object.movement->current_direction = MovementDirection::kUp;
    }
    if (enemy_box.left > player_box.right + 15) {
      if (enemy_box.bottom < player_box.top + 15) {
        object.movement->current_direction = MovementDirection::kDownLeft;
      } else if (enemy_box.top > player_box.bottom - 15) {
        object.movement->current_direction = MovementDirection::kUpLeft;
      }
    }
    if (enemy_box.right < player_box.left - 15) {
      if (enemy_box.bottom < player_box.top + 15) {
        object.movement->current_direction = MovementDirection::kDownRight;
      } else if (enemy_box.top > player_box.bottom - 15) {
        object.movement->current_direction = MovementDirection::kUpRight;
      }
    }
  }
}

bool AIEngine::TimeForNewDecision(GameObject &object) {
  int current_time_ms = SDL_GetTicks();
  int elapsed_time_ms = current_time_ms - object.ai->time_of_last_decision_ms;
  if (elapsed_time_ms >= 8000) {
    return true;
  }
  return false;
}

void AIEngine::NextMove(GameObject &object) {
  object.ai->time_of_last_decision_ms = SDL_GetTicks();
  int random_number = rand() % 100;
  if (object.ai->in_attack_range) {
    object.ai->current_action = ActionType::kAttackPlayer;
  } else {
    if (random_number < 40) {
      object.ai->current_action = ActionType::kChase;
    } else {
      object.ai->current_action = ActionType::kCutOffPlayer;
    }
    random_number = rand() % 100;
    if (random_number < 60) {
      object.movement->speed = 2;
    } else {
      object.movement->speed = 3;
    }
  }
}

void AIEngine::InAttackRangeCheck(GameObject &object, GameObject &player) {
  HitBox player_hb = GetHitBox(player);
  BoundingBox object_bb = GetBoundingBox(object);
  if ((player_hb.left <= object_bb.right + 15) &&
      (player_hb.right >= object_bb.left - 15) &&
      (player_hb.top <= object_bb.bottom + 15) &&
      (player_hb.bottom >= object_bb.top - 15)) {
    if (object.ai->in_attack_range == false) {
      object.ai->entered_attack_range_ms = SDL_GetTicks();
    }
    object.ai->in_attack_range = true;
  } else {
    object.ai->in_attack_range = false;
  }
}
