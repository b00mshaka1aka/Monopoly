#include "QChance.h"

QChance::QChance() : Chance() {}

void QChance::onPlayerStayField(Player* player, Game* game) {
    Chance::onPlayerStayField(player, game);

    infWindow = new QInformationWindow("Карточка шанс", getLastChance()->description, "Ok");
    infWindow->show();
}
