#include "health_engine.h"
#include <iostream>

HealthEngine::HealthEngine(){}

HealthEngine::~HealthEngine(){}

void HealthEngine::Run(GameObject &object){
    if (object.health){
        for (auto& hit_object : object.hit_box->objects_hit)
        {
            //std::cout << "in2" << std::endl;
            if (hit_object == HitBoxType::kMonster && object.health->health > 0){
                object.health->health = object.health->health-1;
                std::cout << "You got hit!" << std::endl;
            }
            if (object.health->health == 0) {
                //std::cout << "You are dead!!" << std::endl;
            }
        }
    }
}