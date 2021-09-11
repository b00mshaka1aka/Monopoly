#pragma once

#include <QVector>

#include "Player.h"
#include "Field.h"
#include "Company.h"
#include "PlayerInterface.h"

class Game {
    PlayerInterface* playerInterface;
    QVector<Player*> playersVector;
    QVector<Field*> fieldsVector;

public:
    Game(QVector<Player*> playersVector, QVector<Field*> fieldsVector);
    Game();
    void start();
    void end();
    static int diceRoll();
    void setPlayerInterface(PlayerInterface* playerInterface);
    void addPlayerToVector(Player* player);
    void addFieldToVector(Field* field);
    QVector<Player*>* getPlayerVector();
    void getPlayerNewPos(Player* player);
    void surrenderPlayer(Player* player);
    void onPlayerPay(Player* player, int money);
    void onPlayerNoMoney(Player* player);
    void onPlayerTurn(Player* player);
    bool isEndGame();
};
