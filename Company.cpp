#include "Company.h"

#include <QApplication>

#include "InformationString.h"
#include "Player.h"
#include "Game.h"

void Company::playerBuyCompany(Player* player, Game* game, Company* company) {
    if(player->getMoney() > company->getCost()) {
        player->subMoney(company->getCost());
        company->setOwner(player);

        QString mon1;
        QString mon2;

        mon1.setNum(company->getCost());
        mon2.setNum(player->getMoney());

        InformationString::setString("Игрок " + player->getName() + " покупает компанию " + company->getName() + " за " +
                                      mon1 + "$. Баланс игрока: " + mon2 + "$.");
        qDebug() << InformationString::getString() << Qt::endl;
    }
    else {
        InformationString::setString("Игрок " + player->getName() + " не смог приобрести компанию, поскольку не "
        "имеет нужного количества денег");

        qDebug() << InformationString::getString() << Qt::endl;
    }
}

void Company::playerPayRent(Player* player, Game* game, Company* company) {
    game->onPlayerPay(player, company->getRent());

    QString mon1;
    QString mon2;

    mon1.setNum(company->getRent());
    mon2.setNum(player->getMoney());

    InformationString::setString("Игрок " + player->getName() + " платит ренту игроку " + company->getOwner()->getName() +
                                  " в сумме: " + mon1 + "$. Баланс игрока: " + mon2 + "$.");

    qDebug() << InformationString::getString() << Qt::endl;
}

void Company::playerOnHisCompany(Player* player) {
    InformationString::setString("Игрок " + player->getName() + " встал на своё поле.");

    qDebug() << InformationString::getString() << Qt::endl;
}

Company::Company(QString name, int cost) {
    this->name = name;
    this->cost = cost;
}

QString Company::getName() {
    return name;
}

int Company::getCost() {
    return cost;
}

Player* Company::getOwner() {
    return owner;
}

void Company::setOwner(Player* player) {
    owner = player;
}

int Company::getRent() {
    return int(cost / 10);
}

void Company::onPlayerStayField(Player* player, Game* game) {
    if (owner == NULL)
        if (player->getMoney() > getCost())
            playerBuyCompany(player, game, this);
        else
            qDebug() << "Игрок " << player->getName() << " отказывается от покупки компании " << getName() <<
                        ". Баланс: " << player->getMoney() << "$." << Qt::endl;

    else if(owner == player)
        playerOnHisCompany(player);
    else if (player->getMoney() > getRent())
        playerPayRent(player, game, this);
}


