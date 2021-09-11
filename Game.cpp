#include "Game.h"

#include <QApplication>
#include <QVector>

#include "InformationString.h"
#include "Random.h"
#include "LargeFields.h"
#include "Company.h"
#include "Chance.h"


QVector<Player*>::iterator getPlayerIteratorOnElement(QVector<Player*> &vector, Player* player) {
    for(QVector<Player*>::iterator i = vector.begin(); i != vector.end(); i++)
        if(*i == player)
            return i;

    return NULL;
}

Game::Game(QVector<Player*> playersVector, QVector<Field*> fieldsVector) {
    playerInterface = new PlayerInterface;

    this->playersVector = playersVector;
    this->fieldsVector = fieldsVector;
}

Game::Game() : playersVector(), fieldsVector() {
    playerInterface = new PlayerInterface;
}

void Game::start() {
    while(!isEndGame())
        for(Player* player : playersVector)
            if(!isEndGame())
                onPlayerTurn(player);
            else
                break;

    end();
}

void Game::end() {
    qDebug() << "Победил игрок " << playersVector[0] -> getName() << "!" << Qt::endl;
}

void Game::setPlayerInterface(PlayerInterface* playerInterface) {
    this->playerInterface = playerInterface;
}

void Game::surrenderPlayer(Player* player) {
    playersVector.erase(getPlayerIteratorOnElement(playersVector, player));

    InformationString::setString("Игрок " + player->getName() + " сдался.");
    qDebug() << InformationString::getString() << Qt::endl;
}

int Game::diceRoll() {
    return Random::get(1, 12);
}

void Game::addPlayerToVector(Player* player) {
    playersVector.push_back(player);
}

void Game::addFieldToVector(Field* field) {
    fieldsVector.push_back(field);
}

QVector<Player*>* Game::getPlayerVector() {
    return &playersVector;
}

void Game::onPlayerNoMoney(Player* player) {
    surrenderPlayer(player);
}

void Game::getPlayerNewPos(Player* player) {
    int newPos = diceRoll();
    int oldPos = player->getPos() + newPos;

    if(oldPos >= fieldsVector.size()) {
        playerInterface->onPlayerPassesStart(player);
        player->setPos(oldPos - fieldsVector.size());
    }
    else
        player->setPos(oldPos);
}

void Game::onPlayerTurn(Player* player) {
    if(!(player->isSkipTurn())) {
        if(!(player->isJail())) {
            InformationString::setString("Ход игрока: " + player->getName());
            qDebug() << InformationString::getString() << Qt::endl;

            getPlayerNewPos(player);
            fieldsVector[player->getPos()]->onPlayerStayField(player, this);
        }
        else
            playerInterface->onPlayerJail(player);
    }
    else
        playerInterface->onPlayerSkipTurn(player);
}

void Game::onPlayerPay(Player* player, int money) {
    if(player->getMoney() > money)
        player->subMoney(money);
    else
        onPlayerNoMoney(player);
}

bool Game::isEndGame() {
    return (playersVector.size() == 1);
}
