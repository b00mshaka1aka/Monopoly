#pragma once

#include <QPixmap>
#include <QLabel>

#include "Player.h"

class QPlayer : public Player {
    QPixmap playerPixmap;
    QLabel playerIcon;

public:
    QPlayer(QString name, int money, QString iconAddress, QWidget* parent);
    void moveIcon(int pos);
    void setPos(int pos);
    QPixmap getPlayerPixmap();
};
