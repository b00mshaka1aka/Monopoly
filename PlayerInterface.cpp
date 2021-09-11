#include "PlayerInterface.h"

#include <QApplication>

#include "Player.h"

void PlayerInterface::onPlayerPassesStart(Player* player) {
    player->addMoney(50);

    qDebug() << "Игрок " << player->getName() << " прошёл круг и получил 50$." << Qt::endl;
}

void PlayerInterface::onPlayerJail(Player* player) {
    if(player->getCountJail() > 1) {
        player->setCountJail(player->getCountJail() - 1);

        qDebug() << "Игрок " << player->getName() << " пропустил ход. Осталось пропустить: "
        << player->getCountJail() << Qt::endl;
    }
    else {
        player->setCountJail(0);
        player->setJail(false);

        qDebug() << "Игрок " << player->getName() << " завершил сидеть в тюрьме." << Qt::endl;
    }

}

void PlayerInterface::onPlayerSkipTurn(Player* player) {
    if(player->isSkipTurn())
        player->setSkipTurn(false);

    qDebug() << "Игрок " << player->getName() << " пропустил ход." << Qt::endl;
}
