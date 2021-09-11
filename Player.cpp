#include "Player.h"

Player::Player(QString name, int money) {
    this->name = name;
    this->money = money;
}

QString Player::getName() {
    return name;
}

int Player::getMoney() {
    return money;
}

void Player::addMoney(int deltaMoney) {
    money += deltaMoney;
}

void Player::subMoney(int deltaMoney) {
    money -= deltaMoney;
}

void Player::setSkipTurn(bool skipTurn) {
    this->skipTurn = skipTurn;
}

bool Player::isSkipTurn() {
    return skipTurn;
}

void Player::setJail(bool jail) {
    this->jail = jail;
}

bool Player::isJail() {
    return jail;
}

void Player::setPos(int pos) {
    this->pos = pos;
}

int Player::getPos() {
    return pos;
}

void Player::addPos(int pos) {
    this->pos += pos;
}

int Player::getCountJail() {
    return countJail;
}

void Player::setCountJail(int countJail) {
    this->countJail = countJail;
}
