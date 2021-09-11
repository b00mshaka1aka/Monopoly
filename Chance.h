#pragma once

#include <QString>
#include <QVector>

#include "Field.h"

struct ChanceCard {
    QString description;
    int add;

    ChanceCard(QString description, int add) {
        this->description = description;
        this->add = add;
    }
};

class Chance : public Field {
    QVector<ChanceCard> chanceCardVector;
    ChanceCard* lastChance = NULL;

public:
    Chance();
    ChanceCard* getLastChance();
    void onPlayerStayField(Player* player, Game* game);
};
