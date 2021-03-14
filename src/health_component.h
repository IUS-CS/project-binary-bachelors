#ifndef HEALTH_COMPONENT_H
#define HEALTH_COMPONENT_H

struct HealthComponent {
  int health; 

  HealthComponent(int hp){
    health = hp;
  }   
  HealthComponent(){
    health = 3;
  }
  ~HealthComponent(){}
};

#endif