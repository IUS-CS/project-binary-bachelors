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

void StartNewAnimation(GameObject &object, AnimationType type) {
  auto &animation_id = GetAnimationId(object);
  for (int i = 0; i < (int)object.animation->animation_list.size(); i++) {
    if (object.animation->animation_list[i].type == type) {
      animation_id = i;
    }
  }
}

void PickAnimation(GameObject &object) {
  auto &animation = GetAnimation(object);
  auto &animation_id = GetAnimationId(object);
  auto &frame_id = GetFrameId(object);
  auto &animation_list = object.animation->animation_list;
  if (animation.cancel_on_key_release) {
    if (InputComponent::Get().attack && object.type == ObjectType::kPlayer) {
      animation_id = 6;
    } else if (object.movement->current_direction != MovementDirection::kNone) {
      switch (object.movement->current_direction) {
      case MovementDirection::kUp:
        if (animation.priority <= animation_list[2].priority) {
          animation_id = 2;
        }
        break;
      case MovementDirection::kDown:
        if (animation_list[animation_id].priority <=
            animation_list[2].priority) {
          animation_id = 0;
        }
        break;
      case MovementDirection::kDownLeft:
      case MovementDirection::kDownRight:
      case MovementDirection::kUpLeft:
      case MovementDirection::kUpRight:
      case MovementDirection::kRight:
      case MovementDirection::kLeft:
        if (animation_list[animation_id].priority <=
            animation_list[2].priority) {
          animation_id = 1;
        }
        break;
      default:
        break;
      }
    } else {
      if (animation_id == 0 || animation_id == 6) {
        animation_id = 3;
      }
      if (animation_id == 1) {
        animation_id = 4;
      }

      if (animation_id == 2) {
        animation_id = 5;
      }
    }
    frame_id = 0;
  }
}
} // namespace

AnimationEngine::AnimationEngine() {}

AnimationEngine::~AnimationEngine() {}

void AnimationEngine::Run(GameObject &object) {
  // std::cout << "In Animation Engine" << std::endl;
  // std::cout << "Took address of object" << std::endl;
  // std::cout << "animation_id set!" << std::endl;
  // std::cout << *animation_id << std::endl;
  if (object.animation) {
    auto &animation = GetAnimation(object);
    // std::cout << "animation set!" << std::endl;
    // Broken line:
    auto &frame_id = GetFrameId(object);
    // std::cout << &frame_id << std::endl;
    // std::cout << "frame_id set!" << std::endl;
    // std::cout << "Hitting first if" << std::endl;
    PickAnimation(object);
    // std::cout << "Animation Picked!" << std::endl;
    if (IsItTimeToChangeFrames(object)) {
      frame_id = (frame_id + 1) % animation.animation_frames.size();
      if (!animation.loop && frame_id == 0) {
        GetAnimationId(object) = 0;
        // std::cout << "SAME OBJECT!!!!" << std::endl;
        PickAnimation(object);
      } else {
        object.sprite->sprite_rect =
            animation.animation_frames[frame_id].source;
      }
      object.animation->start_of_last_animation_frame_ms = SDL_GetTicks();
    }
  }
}
