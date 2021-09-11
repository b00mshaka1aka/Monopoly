#include "QPlayerInterface.h"

#include <QString>

#include "QInformationWindow.h"
#include "QPlayer.h"


void QPlayerInterface::onPlayerPassesStart(Player* player) {
    PlayerInterface::onPlayerPassesStart(player);

    infWindow = new QInformationWindow("Круг", "Вы прошли круг, и за это вам начислено 50$", "Ok");
    infWindow->show();
}

void QPlayerInterface::onPlayerJail(Player* player) {
    PlayerInterface::onPlayerJail(player);

    QString num;
    num.setNum(player->getCountJail());

    infWindow = new QInformationWindow("Тюрьма", "Вы находитесь в тюрьме. Вам осталось пропустить: " + num + "ходов", "Ok");
    infWindow->show();
}

void QPlayerInterface::onPlayerSkipTurn(Player *player) {
    PlayerInterface::onPlayerSkipTurn(player);

    infWindow = new QInformationWindow("Пропуск хода", "Вы пропускаете ход", "Ok");
    infWindow->show();
}
