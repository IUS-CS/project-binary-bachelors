#include "health_engine.h"
#include <iostream>

HealthEngine::HealthEngine(){}

HealthEngine::~HealthEngine(){}

void HealthEngine::Run(GameObject &object){
    if (object.health){
        for (auto& hit_object : object.hit_box->objects_hit)
        {
            if (object.is_active){
            CheckInvincibility(object);
            //std::cout << "in2" << std::endl;
            if (hit_object == HitBoxType::kMonster && object.health->health > 0 && !object.hit_box->is_invincible){
                object.health->health = object.health->health-1;
                object.hit_box->is_invincible = true;
                object.hit_box->time_since_last_hit_ms = SDL_GetTicks();
                std::cout << " got hit!" << std::endl;
            }
            if (object.health->health == 0) {
                object.is_active = false;
                std::cout << "You are dead!" << std::endl;
                std::cout << object.is_active << std::endl;
            }
            }
        }
    }
}

void HealthEngine::CheckInvincibility(GameObject &object){
    int current_time_ms = SDL_GetTicks();
    int elapsed_time_ms = current_time_ms - object.hit_box->time_since_last_hit_ms;
    if (elapsed_time_ms < 2000){
        
    }
    else {
        object.hit_box->is_invincible = false;
    }
}