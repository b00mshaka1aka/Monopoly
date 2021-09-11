#pragma once

class Player;
class Game;

class Field {
public:
    virtual void onPlayerStayField(Player* player, Game* game) = 0;
};
