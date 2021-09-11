#pragma once

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QVector>

#include "QPlayer.h"

class QPlayerInfo {
    QWidget* playerInfoWidget;
    QLabel* playerIcon;
    QVBoxLayout* layout;
    QLabel* playerName;
    QLabel* playerMoney;
    QString name;
    int money;
    QString sMoney;

public:
    QPlayerInfo(QPixmap icon, QString name, int money, QWidget* parent = nullptr) {
        playerInfoWidget = new QWidget(parent);
        playerIcon = new QLabel(playerInfoWidget);
        playerName = new QLabel(playerInfoWidget);
        playerMoney = new QLabel(playerInfoWidget);
        layout = new QVBoxLayout(playerInfoWidget);

        layout->addWidget(playerIcon);
        layout->addWidget(playerName);
        layout->addWidget(playerMoney);

        this->name = name;
        this->money = money;

        icon = icon.scaled(100, 100);
        playerIcon->setPixmap(icon);
        playerName->setText("Игрок: " + name);

        sMoney.setNum(money);
        playerMoney->setText("Баланс: " + sMoney + "$.");

        playerInfoWidget->show();
    }

    QString getName() {
        return name;
    }

    QWidget* getWidget() {
        return playerInfoWidget;
    }

    void update(int money) {
        if((this->money) != money) {
            this->money = money;
            sMoney.setNum(money);
            playerMoney->setText("Баланс: " + sMoney + "$.");
        }
    }
};

class QPlayersInfo {
    QWidget playersInfoWidget;
    QVBoxLayout layout;
    QVector<QPlayerInfo> playersInfo;
    QVector<QPlayer*>* ptrPlayersVector;

public:
    QPlayersInfo(QVector<QPlayer*>* ptrPlayersVector, QWidget* parent = nullptr) : playersInfoWidget(parent),
        layout(&playersInfoWidget), playersInfo() {
        this->ptrPlayersVector = ptrPlayersVector;

        for(QPlayer* player : *ptrPlayersVector) {
            playersInfo.push_back(QPlayerInfo(player->getPlayerPixmap(), player->getName(),
                                             player->getMoney(), &playersInfoWidget));
            layout.addWidget((*(playersInfo.end() - 1)).getWidget());
        }

        playersInfoWidget.show();
    }

    QWidget* getWidget() {
        return &playersInfoWidget;
    }

    void update() {
        if(playersInfo.size() >= (*ptrPlayersVector).size()) {
            for(QVector<QPlayerInfo>::iterator playerInfo = playersInfo.begin(); playerInfo != (playersInfo.end() - 1); playerInfo++) {
                bool isValid = false;

                for(QVector<QPlayer*>::iterator player = ptrPlayersVector->begin(); player != ptrPlayersVector->end(); player++)
                    if((*player)->getName() == (*playerInfo).getName()) {
                        isValid = true;
                        (*playerInfo).update((*player)->getMoney());
                    }

                if(!isValid) {
                    (*playerInfo).getWidget()->close();
                    playersInfo.erase(playerInfo);
                }
            }
        }
        else {
            for(QPlayer* player : (*ptrPlayersVector)) {
                bool isValid = false;

                for(QVector<QPlayerInfo>::iterator playerInfo = playersInfo.begin(); playerInfo != playersInfo.end(); playerInfo++)
                    if(player->getName() == (*playerInfo).getName())
                        isValid = true;

                if(!isValid) {
                    playersInfo.push_back(QPlayerInfo(player->getPlayerPixmap(), player->getName(), player->getMoney(), &playersInfoWidget));
                    layout.addWidget((*(playersInfo.end() - 1)).getWidget());
                }
            }
        }

        playersInfoWidget.close();
        playersInfoWidget.show();
    }
};
