#include "spawn_engine.h"
#include "data/orc.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <random>

namespace {
bool IsItTimeToSpawnEnemies(int last_spawn_time_ms) {
  int current_time_ms = SDL_GetTicks();
  int elapsed_time_ms = current_time_ms - last_spawn_time_ms;
  std::random_device generator;
  std::mt19937 mt(generator());
  std::uniform_int_distribution<int> distribution(0, 5000);
  int random_num = distribution(generator);
  if (elapsed_time_ms >= 12000 + random_num) {
    return true;
  } else {
    return false;
  }
}

void SpawnEnemies(GameObject enemy, int num_of_enemies_to_spawn,
                  std::vector<GameObject> &objects_to_add,
                  std::vector<GameObject> &objects_list) {
  for (int i = 0; i < num_of_enemies_to_spawn; i++) {
    std::random_device generator;
    std::mt19937 mt(generator());
    std::uniform_int_distribution<int> distribution(0, 3);
    int random_num = distribution(mt);
    if (random_num == 0) {
      distribution = std::uniform_int_distribution<int>(-100, 1100);
      random_num = distribution(mt);
      enemy.location->coordinates.x = -100;
      enemy.location->coordinates.y = random_num;
    }
    if (random_num == 1) {
      distribution = std::uniform_int_distribution<int>(-100, 1100);
      random_num = distribution(mt);
      enemy.location->coordinates.x = 1000;
      enemy.location->coordinates.y = random_num;
    }
    if (random_num == 2) {
      distribution = std::uniform_int_distribution<int>(-100, 1100);
      random_num = distribution(mt);
      enemy.location->coordinates.x = random_num;
      enemy.location->coordinates.y = -100;
    }
    if (random_num == 3) {
      distribution = std::uniform_int_distribution<int>(-100, 1100);
      random_num = distribution(mt);
      enemy.location->coordinates.x = random_num;
      enemy.location->coordinates.y = 700;
    }
    enemy.id_num = objects_list.size() + i;
    objects_to_add.push_back(enemy);
  }
}

void PickEnemiesToSpawn(std::vector<GameObject> &objects_to_add,
                        std::vector<GameObject> &objects_list) {
  std::random_device generator;
  std::mt19937 mt(generator());
  std::uniform_int_distribution<int> distribution(0, 99);
  int random_num = distribution(mt);
  int num_of_enemies_to_spawn;
  if (random_num < 45) {
    num_of_enemies_to_spawn = 1;
  } else if (random_num >= 45 && random_num < 80) {
    num_of_enemies_to_spawn = 2;
  } else {
    num_of_enemies_to_spawn = 3;
  }

  distribution = std::uniform_int_distribution<int>(0, 99);
  random_num = distribution(generator);

  if (random_num >= 0 && random_num < 95) {
    Orc orc_data;
    GameObject orc = orc_data.LoadOrc({0, 0});
    SpawnEnemies(orc, num_of_enemies_to_spawn, objects_to_add, objects_list);
  } else {
    std::cout << "Not Spawning" << std::endl;
  }
}
} // namespace
SpawnEngine::SpawnEngine() {}
SpawnEngine::~SpawnEngine() {}
void SpawnEngine::Run(std::vector<GameObject> &objects_to_add,
                      std::vector<GameObject> &objects_list) {
  if (IsItTimeToSpawnEnemies(last_spawn_time_ms)) {
    last_spawn_time_ms = SDL_GetTicks();
    PickEnemiesToSpawn(objects_to_add, objects_list);
  }
}
