#include "Chance.h"

#include <QApplication>

#include "Player.h"
#include "Game.h"
#include "Random.h"
#include "InformationString.h"

Chance::Chance() : chanceCardVector() {
    chanceCardVector.push_back(ChanceCard("К вам пришла налоговая, нужно заплатить 100$", -100));
    chanceCardVector.push_back(ChanceCard("Вам подарили на день рождения 500$", 500));
    chanceCardVector.push_back(ChanceCard("Из-за кризиса вы потеряли 300$", -300));
    chanceCardVector.push_back(ChanceCard("Вы шли пешком и нашли 200$ по дороге", 200));
    chanceCardVector.push_back(ChanceCard("У вас украли 400$", -400));
}

ChanceCard* Chance::getLastChance() {
    return lastChance;
}

void Chance::onPlayerStayField(Player* player, Game* game) {
    int size = chanceCardVector.size() - 1;
    int i = Random::get(0, size);

    if(chanceCardVector[i].add < 0)
        game->onPlayerPay(player, -chanceCardVector[i].add);
    else
        player->addMoney(chanceCardVector[i].add);

    lastChance = &(chanceCardVector[i]);

    QString mon;
    mon.setNum(player->getMoney());

    InformationString::setString("Игрок " + player->getName() + " встал на поле \"Шанс\" и вытянул карточку: " +
                                  chanceCardVector[i].description + ". Баланс: " + mon + "$.");
    qDebug() << InformationString::getString() << Qt::endl;
}
