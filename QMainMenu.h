#pragma once

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "QGame.h"

class QMainMenu : public QObject {
    QWidget mainMenuWidget;
    QLabel logo;
    QPushButton startGame;
    QPushButton leaveGame;
    QVBoxLayout layout;
    QGame* game;
    QWidget* parentWidget;

public:
    QMainMenu(QWidget* parent = nullptr);
    void show();

public slots:
    void onClickedStartGame();
};
