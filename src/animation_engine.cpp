#include "animation_engine.h"
#include "input_component.h"
#include <iostream>

namespace {
int &GetAnimationId(GameObject &object) {
  return object.animation->current_animation_id;
}

Animation &GetAnimation(GameObject &object) {
  return object.animation->animation_list[GetAnimationId(object)];
}

int &GetFrameId(GameObject &object) {
  Animation &animation = GetAnimation(object);
  return animation.current_frame_id;
}

bool IsItTimeToChangeFrames(GameObject &object) {
  auto &animation = GetAnimation(object);
  auto &frame_id = GetFrameId(object);
  int current_time_ms = SDL_GetTicks();
  int elapsed_time_ms =
      current_time_ms - object.animation->start_of_last_animation_frame_ms;

  if (elapsed_time_ms >=
      animation.animation_frames[frame_id].time_before_next_frame) {
    return true;
  }
  return false;
}

void UpdateAnimationId(int &animation_id, int &frame_id, int next_animation_id,
                       GameObject &object) {
  if (animation_id != next_animation_id) {
    animation_id = next_animation_id;
    if (object.type == ObjectType::kPlayer) {
    }
    object.animation->start_of_last_animation_frame_ms = SDL_GetTicks();
  }
}

void PickAnimation(GameObject &object) {
  auto &animation = GetAnimation(object);
  auto &animation_id = GetAnimationId(object);
  auto &frame_id = GetFrameId(object);
  auto &animation_list = object.animation->animation_list;
  if (object.type == ObjectType::kPlayer || object.type == ObjectType::kEnemy) {
    if (object.hit_box->is_hit) {
      if (object.location->direction_faced == DirectionFaced::kDown) {
        if (object.location->flip) {
          UpdateAnimationId(animation_id, frame_id, 13, object);
        } else {
          UpdateAnimationId(animation_id, frame_id, 12, object);
        }
      }
      if (object.location->direction_faced == DirectionFaced::kRight) {
        UpdateAnimationId(animation_id, frame_id, 14, object);
      }
      if (object.location->direction_faced == DirectionFaced::kLeft) {
        UpdateAnimationId(animation_id, frame_id, 15, object);
      }
      if (object.location->direction_faced == DirectionFaced::kUp) {
        if (object.location->flip) {
          UpdateAnimationId(animation_id, frame_id, 17, object);
        } else {
          UpdateAnimationId(animation_id, frame_id, 16, object);
        }
      }
    } else if (InputComponent::Get().attack &&
               object.type == ObjectType::kPlayer) {
      object.animation->is_attacking = true;
      if (object.location->direction_faced == DirectionFaced::kDown) {
        if (object.location->flip) {
          UpdateAnimationId(animation_id, frame_id, 7, object);
        } else {
          UpdateAnimationId(animation_id, frame_id, 6, object);
        }
      }
      if (object.location->direction_faced == DirectionFaced::kRight) {
        UpdateAnimationId(animation_id, frame_id, 8, object);
      }
      if (object.location->direction_faced == DirectionFaced::kLeft) {
        UpdateAnimationId(animation_id, frame_id, 9, object);
      }
      if (object.location->direction_faced == DirectionFaced::kUp) {
        if (object.location->flip) {
          UpdateAnimationId(animation_id, frame_id, 11, object);
        } else
          UpdateAnimationId(animation_id, frame_id, 10, object);
      }
    } else {
      int current_priority = animation.priority;
      switch (object.movement->current_direction) {
      case MovementDirection::kUp:
        if (current_priority <= animation_list[2].priority) {
          UpdateAnimationId(animation_id, frame_id, 2, object);
          object.location->direction_faced = DirectionFaced::kUp;
        }
        break;
      case MovementDirection::kDown:
        if (current_priority <= animation_list[0].priority) {
          object.location->direction_faced = DirectionFaced::kDown;
          UpdateAnimationId(animation_id, frame_id, 0, object);
        }
        break;
      case MovementDirection::kDownLeft:
      case MovementDirection::kUpLeft:
      case MovementDirection::kLeft:
        if (current_priority <= animation_list[1].priority) {
          UpdateAnimationId(animation_id, frame_id, 1, object);
          object.location->direction_faced = DirectionFaced::kLeft;
        }
        break;
      case MovementDirection::kDownRight:
      case MovementDirection::kUpRight:
      case MovementDirection::kRight:
        if (current_priority <= animation_list[1].priority) {
          UpdateAnimationId(animation_id, frame_id, 1, object);
          object.location->direction_faced = DirectionFaced::kRight;
        }
        break;
      case MovementDirection::kNone:
        if (object.location->direction_faced == DirectionFaced::kDown &&
            !object.animation->is_attacking) {
          UpdateAnimationId(animation_id, frame_id, 3, object);
        }
        if ((object.location->direction_faced == DirectionFaced::kRight ||
             object.location->direction_faced == DirectionFaced::kLeft) &&
            !object.animation->is_attacking) {
          UpdateAnimationId(animation_id, frame_id, 4, object);
        }

        if (object.location->direction_faced == DirectionFaced::kUp &&
            !object.animation->is_attacking) {
          UpdateAnimationId(animation_id, frame_id, 5, object);
        }
        break;
      }
    }
  } else {
    GetAnimationId(object) = 0;
  }
}

} // namespace

AnimationEngine::AnimationEngine() {}

AnimationEngine::~AnimationEngine() {}

void AnimationEngine::Run(GameObject &object) {
  if (object.animation) {
    PickAnimation(object);
    auto &animation = GetAnimation(object);
    auto &frame_id = GetFrameId(object);
    int new_frame_id;
    Animation new_animation;

    if (IsItTimeToChangeFrames(object)) {
      frame_id = (frame_id + 1) % animation.animation_frames.size();
      if (!animation.loop && frame_id == 0) {
        if (object.type == ObjectType::kPlayer ||
            object.type == ObjectType::kEnemy) {
          if (object.animation->is_attacking) {
            if (object.location->direction_faced == DirectionFaced::kDown) {
              object.animation->is_attacking = false;
              GetAnimationId(object) = 3;
            }
            if (object.location->direction_faced == DirectionFaced::kRight ||
                object.location->direction_faced == DirectionFaced::kLeft) {
              object.animation->is_attacking = false;
              GetAnimationId(object) = 4;
            }
            if (object.location->direction_faced == DirectionFaced::kUp) {
              object.animation->is_attacking = false;
              GetAnimationId(object) = 5;
            }
          }
          if (object.hit_box->is_hit) {
            if (object.location->direction_faced == DirectionFaced::kDown) {
              object.hit_box->is_hit = false;
              GetAnimationId(object) = 3;
            }
            if (object.location->direction_faced == DirectionFaced::kRight ||
                object.location->direction_faced == DirectionFaced::kLeft) {
              object.hit_box->is_hit = false;
              GetAnimationId(object) = 4;
            }
            if (object.location->direction_faced == DirectionFaced::kUp) {
              object.hit_box->is_hit = false;
              GetAnimationId(object) = 5;
            }
          }
          PickAnimation(object);
        }
      }
      object.animation->start_of_last_animation_frame_ms = SDL_GetTicks();
    }
    new_animation = GetAnimation(object);
    new_frame_id = GetFrameId(object);
    object.sprite->sprite_rect =
        new_animation.animation_frames[frame_id].source;
    object.sprite->offset = new_animation.animation_frames[new_frame_id].offset;
  }
}
