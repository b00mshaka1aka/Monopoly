#pragma once

class Player;

class PlayerInterface {
public:
    virtual void onPlayerPassesStart(Player* player);
    virtual void onPlayerJail(Player* player);
    virtual void onPlayerSkipTurn(Player* player);
};
