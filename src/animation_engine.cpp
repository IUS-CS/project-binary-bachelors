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

void UpdateAnimationId(int &animation_id, int &frame_id,
                       int next_animation_id) {
  if (animation_id != next_animation_id) {
    frame_id = 0;
  }
  animation_id = next_animation_id;
}

void PickAnimation(GameObject &object) {
  auto &animation = GetAnimation(object);
  auto &animation_id = GetAnimationId(object);
  auto &frame_id = GetFrameId(object);
  auto &animation_list = object.animation->animation_list;
  if (InputComponent::Get().attack && object.type == ObjectType::kPlayer) {
    UpdateAnimationId(animation_id, frame_id, 6);
  } else {
    int current_priority = animation.priority;
    switch (object.movement->current_direction) {
    case MovementDirection::kUp:
      if (current_priority <= animation_list[2].priority) {
        UpdateAnimationId(animation_id, frame_id, 2);
      }
      break;
    case MovementDirection::kDown:
      if (current_priority <= animation_list[0].priority) {
        UpdateAnimationId(animation_id, frame_id, 0);
      }
      break;
    case MovementDirection::kDownLeft:
    case MovementDirection::kDownRight:
    case MovementDirection::kUpLeft:
    case MovementDirection::kUpRight:
    case MovementDirection::kRight:
    case MovementDirection::kLeft:
      if (current_priority <= animation_list[1].priority) {
        UpdateAnimationId(animation_id, frame_id, 1);
      }
      break;
    case MovementDirection::kNone:
      if (animation_id == 0) {
        UpdateAnimationId(animation_id, frame_id, 3);
      }
      if (animation_id == 1) {
        UpdateAnimationId(animation_id, frame_id, 4);
      }

      if (animation_id == 2) {
        UpdateAnimationId(animation_id, frame_id, 5);
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
        GetAnimationId(object) = 0;
        PickAnimation(object);
      } else {
        object.sprite->sprite_rect =
            animation.animation_frames[frame_id].source;
      }
      object.animation->start_of_last_animation_frame_ms = SDL_GetTicks();
    }
  }
}
