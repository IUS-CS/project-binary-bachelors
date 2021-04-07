#include "animation_engine.h"

AnimationEngine::AnimationEngine() {}

AnimationEngine::~AnimationEngine() {}

void AnimationEngine::Run(GameObject &object) {
  if (object.animation) {
    PickAnimation(object);
    if (IsItTimeToChangeFrames(object)) {
      if (object.animation
              ->animation_list[object.animation->current_animation_id]
              .current_frame_id <
          (int)object.animation
                  ->animation_list[object.animation->current_animation_id]
                  .animation_frames.size() -
              1) {
        object.animation->animation_list[object.animation->current_animation_id]
            .current_frame_id += 1;
        object.sprite->sprite_rect =
            object.animation
                ->animation_list[object.animation->current_animation_id]
                .animation_frames
                    [object.animation
                         ->animation_list[object.animation
                                              ->current_animation_id]
                         .current_frame_id]
                .source;
      } else {
        object.animation->animation_list[object.animation->current_animation_id]
            .current_frame_id = 0;
        object.sprite->sprite_rect =
            object.animation
                ->animation_list[object.animation->current_animation_id]
                .animation_frames
                    [object.animation
                         ->animation_list[object.animation
                                              ->current_animation_id]
                         .current_frame_id]
                .source;
      }
      object.animation->start_of_last_animation_frame_ms = SDL_GetTicks();
    }
  }
}

bool AnimationEngine::IsItTimeToChangeFrames(GameObject &object) {
  int current_time_ms = SDL_GetTicks();
  int elapsed_time_ms =
      current_time_ms - object.animation->start_of_last_animation_frame_ms;

  if (elapsed_time_ms >=
      object.animation->animation_list[object.animation->current_animation_id]
          .animation_frames
              [object.animation
                   ->animation_list[object.animation->current_animation_id]
                   .current_frame_id]
          .time_before_next_frame) {
    return true;
  }
  return false;
}

void AnimationEngine::StartNewAnimation(GameObject &object,
                                        AnimationType type) {
  for (int i = 0; i < (int)object.animation->animation_list.size(); i++) {
    if (object.animation->animation_list[i].type == type) {
      object.animation->current_animation_id = i;
    }
  }
}

void AnimationEngine::PickAnimation(GameObject &object) {
  switch (object.movement->current_direction) {
  case MovementDirection::kUp:
    object.animation->current_animation_id = 2;
    break;
  case MovementDirection::kDown:
    object.animation->current_animation_id = 0;
    break;
  case MovementDirection::kDownLeft:
  case MovementDirection::kDownRight:
  case MovementDirection::kUpLeft:
  case MovementDirection::kUpRight:
  case MovementDirection::kRight:
  case MovementDirection::kLeft:
    object.animation->current_animation_id = 1;
    break;
  case MovementDirection::kNone:
    if (object.animation->current_animation_id == 0) {
      object.animation->current_animation_id = 3;
    }
    if (object.animation->current_animation_id == 1) {
      object.animation->current_animation_id = 4;
    }

    if (object.animation->current_animation_id == 2) {
      object.animation->current_animation_id = 5;
    }
    break;
  default:
    break;
  }
}
