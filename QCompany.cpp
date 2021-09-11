#include "QCompany.h"

#include <QString>

#include "Player.h"
#include "Game.h"

QCompany::QCompany(QString name, int cost) : Company(name, cost) { }

void QCompany::onClickedBuyCompany() {
    Company::playerBuyCompany(tPlayer, tGame, this);
    buyCompanyWindow->close();
}

void QCompany::onPlayerStayField(Player* player, Game* game) {
    tPlayer = player;
    tGame = game;

    if(getOwner() == NULL) {
        buyCompanyWindow = new QBuyCompanyWindow("Покупка компании", "Вы желаете приобрести " + getName() + " ?", "Да", "Нет");
        buyCompanyWindow->show();

        QObject::connect(buyCompanyWindow->getPushButton1(), &QPushButton::clicked,
                         this, &QCompany::onClickedBuyCompany);
        QObject::connect(buyCompanyWindow->getPushButton2(), SIGNAL(clicked()), buyCompanyWindow, SLOT(close()));
    }
    else if(getOwner() == player) {
        infWindow = new QInformationWindow("Моя компания", "Вы встали на свою компанию", "Ok");
        infWindow->show();
    }
    else {
        QString num;
        num.setNum(getRent());

        infWindow = new QInformationWindow("Оплата аренды", "Вы должны заплатить ренту игроку " + (player->getName()) +
                                   " в размере: " + num + "$.", "Заплатить");
        infWindow->show();

        playerPayRent(player, game, this);
    }
}

