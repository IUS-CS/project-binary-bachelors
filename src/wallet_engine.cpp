#include "wallet_engine.h"
#include <iostream>

WalletEngine::WalletEngine() {}

WalletEngine::~WalletEngine() {}

void WalletEngine::Run(GameObject &object) { 
  if (object.wallet) {
    for (auto &hit_object : object.objects_hit) {
      if (object.is_active) {
        if (hit_object->type == ObjectType::kRupee &&
            object.type == ObjectType::kPlayer) {
          object.wallet->rupees = object.wallet->rupees + 1;
          hit_object->is_active = false;

          std::cout << "Count: " << object.wallet->rupees << std::endl;
        }
        else if (hit_object->type == ObjectType::kBlueRupee &&
                 object.type == ObjectType::kPlayer) {
          object.wallet->rupees = object.wallet->rupees + 5;
          hit_object->is_active = false;

          std:: cout << "Count: " << object.wallet->rupees << std::endl;
        }
      }
    }
  }
}


