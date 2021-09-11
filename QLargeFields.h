#pragma once

#include "LargeFields.h"

#include "QInfWindows.h"

class QStart : public Start, QInfWindows {
public:
    QStart(int money) : Start(money) { }

    void onPlayerStayField(Player* player, Game* game) {
        infWindow = new QInformationWindow("Поле \"Старт\"", "Вы попали на поле старт. В качестве бонуса вам начислено 100$.", "Ok");
        infWindow->show();

        Start::onPlayerStayField(player, game);
    }
};

class QVoidField : public VoidField, QInfWindows {
public:
    QVoidField() {}

    void onPlayerStayField(Player* player, Game* game) {
        infWindow = new QInformationWindow("Пустое поле", "Вы попали на пустое поле, на котором не нужно ничего делать", "Ok");
        infWindow->show();
    }
};

class QJail : public Jail, QInfWindows {
public:
    QJail() {}

    void onPlayerStayField(Player* player, Game* game) {
        infWindow = new QInformationWindow("Поле \"Тюрьма\"", "Вы попали на поле тюрьма. В наказание вы пропустите 3 хода и заплатите 100$.", "Ok");
        infWindow->show();

        Jail::onPlayerStayField(player, game);
    }
};

class QSkipTurn : public SkipTurn, QInfWindows {
public:
    QSkipTurn() {}

    void onPlayerStayField(Player* player, Game* game) {
       infWindow = new QInformationWindow("Поле \"Пропуск хода\"", "В попали на поле пропуск хода, поэтому Вы пропускаете ход", "Ok");
       infWindow->show();

       SkipTurn::onPlayerStayField(player, game);
    }
};
