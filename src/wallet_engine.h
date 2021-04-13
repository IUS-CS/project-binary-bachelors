#ifndef WALLET_ENGINE_H
#define WALLET_ENGINE_H
#include "game_object.h"

// This engine will determine the value of player's wallet
class WalletEngine {
public:
  WalletEngine();
  ~WalletEngine();
  void Run(GameObject &object);
};
#endif
