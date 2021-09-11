#pragma once

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QLineEdit>

#include "QPlayer.h"

class QPlayerInfoWidget {
    QWidget playerInfoWidget;
    QLabel mainText;
    QLabel nameText;
    QLineEdit nameLineEdit;
    QLabel iconText;
    QLabel iconAddress;
    QLabel iconLabel;

public:
    QPlayerInfoWidget(QWidget* parent = nullptr) : playerInfoWidget(parent),
        mainText("Введите информацию о игроке", &playerInfoWidget), nameText("Введите имя игрока", &playerInfoWidget),
        nameLineEdit(&playerInfoWidget), iconText("Укажите путь к иконке игрока: ", &playerInfoWidget),
        iconAddress(&playerInfoWidget)
    {

    }
};

class QPlayersInfoWindow {

};
