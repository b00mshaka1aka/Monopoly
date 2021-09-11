#pragma once

#include "Chance.h"
#include "QInfWindows.h"

class QChance : public Chance, QInfWindows {
public:
    QChance();
    void onPlayerStayField(Player* player, Game* game);
};
