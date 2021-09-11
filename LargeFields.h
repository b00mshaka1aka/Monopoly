#pragma once

#include "Field.h"

#include <QApplication>

#include "Player.h"
#include "Game.h"

class Start : public Field {
    int money;

public:
    Start(int money) {
        this->money = money;
    }

    void onPlayerStayField(Player* player, Game* game) {
        player->addMoney(money);

        qDebug() << "Игрок " << player->getName() << " попал на поле \"Старт\" и получает бонус в размере " <<
                    money << "$. Баланс: " << player->getMoney() << "$." << Qt::endl;
    }
};

class SkipTurn : public Field {
public:
    SkipTurn() {}
    void onPlayerStayField(Player* player, Game* game) {
        player->setSkipTurn(true);

        qDebug() << "Игрок " << player->getName() << " попал на поле \"Пропуск хода\" и пропукает ход. Баланс: " <<
                    player->getMoney() << "$." << Qt::endl;
    }
};

class VoidField : public Field {
public:
    VoidField() {}
    void onPlayerStayField(Player* player, Game* game) {
        qDebug() << "Игрок " << player->getName() << " попал на \"Пустое поле\" и ничего не делает. Баланс: " <<
                    player->getMoney() << "$." << Qt::endl;
    }
};

class Jail : public Field {
    int money;
    int countSkip;

public:
    Jail(int money, int countSkip) {
        this->money = money;
        This->countJail = countJail;
    }

    void onPlayerStayField(Player* player, Game* game) {
        player->setJail(true);
        player->setCountJail(countJail);
        game->onPlayerPay(player, money);

        qDebug() << "Игрок " << player->getName() << " попал в тюрьму, за выход он должен "
        "заплатить и пропустить несколько ходов. Баланс: " << player->getMoney() << "$." << Qt::endl;
    }
};
