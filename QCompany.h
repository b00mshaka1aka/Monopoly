#pragma once

#include <QObject>

#include "QInfWindows.h"
#include "Company.h"

class QCompany : public QObject, public Company, QInfWindows, QBuyCompanyWindows {
    Player* tPlayer;
    Game* tGame;
public:
    QCompany(QString name, int cost);
    void onPlayerStayField(Player* player, Game* game);

public slots:
    void onClickedBuyCompany();
};
