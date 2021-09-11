#pragma once

#include <QObject>

#include "QCompany.h"
#include "QChance.h"
#include "QGameWindow.h"
#include "QLargeFields.h"
#include "QPlayer.h"
#include "QInfWindows.h"
#include "Game.h"

class QGame : public QObject, Game, QInfWindows {
    QGameWindow gameWindow;
    QVector<Player*>::iterator currentPlayer = NULL;
    bool turn = false;

public:
    QGame(QWidget* parent);
    void start();
    void endTurn();
    void end();

public slots:
    void onClickedRollDice();
    void onClickedSurrender();
};
