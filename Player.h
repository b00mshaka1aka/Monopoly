#pragma once

#include <QString>

class Player {
    QString name;
    int money;
    int pos = 0;

    bool skipTurn = false;
    bool jail = false;
    int countJail = 0;

public:
    Player(QString name, int money);
    QString getName();
    int getMoney();
    void addMoney(int deltaMoney);
    void subMoney(int deltaMoney);
    void setSkipTurn(bool skipTurn);
    bool isSkipTurn();
    void setJail(bool jail);
    bool isJail();
    virtual void setPos(int pos);
    int getPos();
    void addPos(int pos);
    int getCountJail();
    void setCountJail(int countJail);
};
