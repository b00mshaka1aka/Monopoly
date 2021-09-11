#pragma once

#include <QString>

#include "Field.h"

class Company : public Field {
    QString name;
    int cost;
    Player* owner = NULL;

public:
    Company(QString name, int cost);
    QString getName();
    int getCost();
    Player* getOwner();
    void setOwner(Player* player);
    int getRent();

    void playerBuyCompany(Player* player, Game* game, Company* company);
    void playerPayRent(Player* player, Game* game, Company* company);
    void playerOnHisCompany(Player* player);

    void onPlayerStayField(Player* player, Game* game);
};
