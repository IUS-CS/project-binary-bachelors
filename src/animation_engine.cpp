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
  std::cout << "Updating animation id to: " << animation_id << std::endl;
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
    if (object.type == ObjectType::kPlayer) {
      std::cout << "Movement direction: "
                << (int)object.movement->current_direction << std::endl;
    }
    int current_priority = animation.priority;
    std::cout << "Current priority is: " << current_priority << std::endl;
    std::cout << "Up priority is: " << animation_list[2].priority << std::endl;
    switch (object.movement->current_direction) {
    case MovementDirection::kUp:
      if (current_priority <= animation_list[2].priority) {
        UpdateAnimationId(animation_id, frame_id, 2);
      }
      std::cout << "Bad Priority" << std::endl;
      break;
    case MovementDirection::kDown:
      if (current_priority <= animation_list[0].priority) {
        UpdateAnimationId(animation_id, frame_id, 3);
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
  // std::cout << "In Animation Engine" << std::endl;
  // std::cout << "Took address of object" << std::endl;
  // std::cout << "animation_id set!" << std::endl;
  // std::cout << *animation_id << std::endl;
  if (object.animation) {
    // std::cout << "animation set!" << std::endl;
    // Broken line:
    // auto &animation_id = GetAnimationId(object);
    // std::cout << &frame_id << std::endl;
    // std::cout << "frame_id set!" << std::endl;
    // std::cout << "Hitting first if" << std::endl;
    PickAnimation(object);
    auto &animation = GetAnimation(object);
    auto &frame_id = GetFrameId(object);
    // std::cout << "Animation Picked!" << std::endl;
    if (IsItTimeToChangeFrames(object)) {
      // std::cin.get();
      std::cout << object.animation->start_of_last_animation_frame_ms
                << std::endl;
      // std::cout << object.sprite->sprite_sheet_name << std::endl;
      // std::cout << "changing frame" << std::endl;
      // std::cout << frame_id << std::endl;
      if (object.type == ObjectType::kPlayer) {
        // std::cout << animation_id << std::endl;
        std::cout << "AnimationId: " << GetAnimationId(object) << std::endl;
        std::cout << "List size: " << animation.animation_frames.size()
                  << std::endl;
        std::cout << "List size: "
                  << object.animation->animation_list[GetAnimationId(object)]
                         .animation_frames.size()
                  << std::endl;
        std::cout << "Time to chage frames! frame no before change: "
                  << frame_id << std::endl;
      }
      frame_id = (frame_id + 1) % animation.animation_frames.size();
      // std::cout << "Frame no after change: " << frame_id << std::endl;
      if (!animation.loop && frame_id == 0) {
        // std::cout << "ending animation" << std::endl;
        GetAnimationId(object) = 0;
        // std::cout << "SAME OBJECT!!!!" << std::endl;
        PickAnimation(object);
      } else {
        object.sprite->sprite_rect =
            animation.animation_frames[frame_id].source;
      }
      object.animation->start_of_last_animation_frame_ms = SDL_GetTicks();
    } else {
      // std::cout << "Not time" << std::endl;
    }
  }
}
