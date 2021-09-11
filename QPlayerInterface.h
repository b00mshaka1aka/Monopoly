#pragma once

#include "PlayerInterface.h"
#include "QInfWindows.h"

class QPlayerInterface : public PlayerInterface, QInfWindows {
public:
    void onPlayerPassesStart(Player* player);
    void onPlayerJail(Player* player);
    void onPlayerSkipTurn(Player* player);
};
