#include "QPlayer.h"

QPlayer::QPlayer(QString name, int money, QString iconAddress, QWidget* parent) : Player(name, money),
    playerPixmap(iconAddress), playerIcon(parent) {
    playerPixmap = playerPixmap.scaled(30, 30);

    playerIcon.setPixmap(playerPixmap);
    playerIcon.resize(playerPixmap.size());
    playerIcon.show();
    moveIcon(Player::getPos());
}

void QPlayer::setPos(int pos) {
    Player::setPos(pos);
    moveIcon(pos);
}

void QPlayer::moveIcon(int pos) {
    int startX = 37;
    int startY = 38;
    int deltaA = 71;
    int deltaB = 53;
    int x, y;

    if((pos >= 0) && (pos < 9)) {
        x = startX + (pos > 0) * (deltaA + (pos - 1) * (pos != 8) * deltaB) + (pos == 8) * (deltaA + 6 * deltaB);
        y = startY;
    }
    else if ((pos >= 9) && (pos < 17)) {
        x = startX + 2 * deltaA + 6 * deltaB;
        y = startY + (pos > 8) * (deltaA + (pos - 9) * (pos != 16) * deltaB) + (pos == 16) * (deltaA + 6 * deltaB);
    }
    else if((pos >= 17) && (pos < 25)) {
        x = startX + (pos < 24) * (deltaA + (-1) * (pos - 23) * deltaB);
        y = startY + 2 * deltaA + 6 * deltaB;
    }
    else {
        x = startX;
        y = startY + (deltaA + (-1) * (pos - 31) * deltaB);
    }

    playerIcon.move(x, y);
}

QPixmap QPlayer::getPlayerPixmap() {
    return playerPixmap;
}
