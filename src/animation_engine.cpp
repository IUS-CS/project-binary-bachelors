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
  if (InputComponent::Get().attack && object.type == ObjectType::kPlayer) {
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
}

} // namespace

AnimationEngine::AnimationEngine() {}

AnimationEngine::~AnimationEngine() {}

void AnimationEngine::Run(GameObject &object) {
  if (object.animation) {
    PickAnimation(object);
    auto &animation = GetAnimation(object);
    auto &frame_id = GetFrameId(object);

    if (IsItTimeToChangeFrames(object)) {
      frame_id = (frame_id + 1) % animation.animation_frames.size();
      if (!animation.loop && frame_id == 0) {
        if (object.location->direction_faced == DirectionFaced::kDown) {
          object.animation->is_attacking = false;
          GetAnimationId(object) = 3;
        }
        if (object.location->direction_faced == DirectionFaced::kRight ||
            object.location->direction_faced == DirectionFaced::kLeft) {
          object.animation->is_attacking = false;
          GetAnimationId(object) = 4;
        }
        PickAnimation(object);
      }
      object.animation->start_of_last_animation_frame_ms = SDL_GetTicks();
    }
    object.sprite->sprite_rect =
        GetAnimation(object).animation_frames[frame_id].source;
  }
}
