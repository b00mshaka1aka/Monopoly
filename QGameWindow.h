#pragma once

#include <QWidget>
#include <QWindow>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "QPlayersInfo.h"

class QGameWindow {
    QWidget* mainWidget;
    QWidget gameWidget;
    QWidget infoWidget;
    QPlayersInfo playersInfo;
    QVBoxLayout layout;
    QHBoxLayout buttonLayout;
    QPixmap gameboardPixmap;
    QLabel gameboard;
    QLabel infString;
    QPushButton surrender;
    QPushButton rollDice;
    QPushButton endGame;

public:
    QGameWindow(QVector<QPlayer*>* ptrPlayersVector, QWidget* parent = nullptr);
    void show();
    void setTextInfString(QString text);
    QPushButton* getSurrenderButton();
    QPushButton* getEndGameButton();
    QPushButton* getRollDiceButton();
    QPlayersInfo* getPlayersInfo();
};
