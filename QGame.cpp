#include "QGame.h"

#include "QInformationWindow.h"
#include "InformationString.h"
#include "QPlayerInterface.h"

QGame::QGame(QWidget* parent) : Game(), gameWindow((QVector<QPlayer*>*)Game::getPlayerVector(), parent) {
    Game::setPlayerInterface(new QPlayerInterface);

    Game::addPlayerToVector(new QPlayer("Михаил", 2000, "C:\\Users\\Shish\\Documents\\QtProjects\\Monopoly\\PlayerIcons\\ball.png", parent));
    Game::addPlayerToVector(new QPlayer("Игорь", 2000, "C:\\Users\\Shish\\Documents\\QtProjects\\Monopoly\\PlayerIcons\\ball.png", parent));

    gameWindow.getPlayersInfo()->update();

    Game::addFieldToVector(new QStart(100));
    Game::addFieldToVector(new QCompany("McDonalds", 50));
    Game::addFieldToVector(new QCompany("KFC", 60));
    Game::addFieldToVector(new QCompany("BurgerKing", 70));
    Game::addFieldToVector(new QChance());
    Game::addFieldToVector(new QCompany("Audi", 80));
    Game::addFieldToVector(new QCompany("BMW", 90));
    Game::addFieldToVector(new QCompany("Mercedes-Benz", 100));
    Game::addFieldToVector(new QVoidField());
    Game::addFieldToVector(new QCompany("Apple", 110));
    Game::addFieldToVector(new QCompany("Microsoft", 120));
    Game::addFieldToVector(new QCompany("Nokia", 130));
    Game::addFieldToVector(new QChance());
    Game::addFieldToVector(new QCompany("IEK", 140));
    Game::addFieldToVector(new QCompany("Legrand", 150));
    Game::addFieldToVector(new QCompany("ABB", 160));
    Game::addFieldToVector(new QSkipTurn());
    Game::addFieldToVector(new QCompany("Adidas", 170));
    Game::addFieldToVector(new QCompany("Puma", 180));
    Game::addFieldToVector(new QCompany("Nike", 190));
    Game::addFieldToVector(new QChance());
    Game::addFieldToVector(new QCompany("Билайн", 200));
    Game::addFieldToVector(new QCompany("ТЕЛЕ2", 210));
    Game::addFieldToVector(new QCompany("Мегафон", 220));
    Game::addFieldToVector(new QJail());
    Game::addFieldToVector(new QCompany("Магнит", 230));
    Game::addFieldToVector(new QCompany("Пятёрочка", 240));
    Game::addFieldToVector(new QCompany("Перекрёсток", 250));
    Game::addFieldToVector(new QChance());
    Game::addFieldToVector(new QCompany("Vaporesso", 260));
    Game::addFieldToVector(new QCompany("Smoant", 270));
    Game::addFieldToVector(new QCompany("Smoke", 280));

    QObject::connect(gameWindow.getSurrenderButton(), &QPushButton::clicked, this, &QGame::onClickedSurrender);
    QObject::connect(gameWindow.getRollDiceButton(), &QPushButton::clicked, this, &QGame::onClickedRollDice);
    QObject::connect(gameWindow.getEndGameButton(), SIGNAL(clicked()), parent, SLOT(close()));
}

void QGame::start() {
    gameWindow.show();
    currentPlayer = Game::getPlayerVector()->begin();
}

void QGame::end() {
    Game::end();

    infWindow = new QInformationWindow("Конец игры", "Победил игрок " + ((*getPlayerVector())[0])->getName() + "!", "Ok");
    infWindow->show();
}

void QGame::endTurn() {
    if(currentPlayer != (Game::getPlayerVector()->end() - 1))
         ++currentPlayer;
    else
        currentPlayer = Game::getPlayerVector()->begin();

    gameWindow.getPlayersInfo()->update();
    gameWindow.setTextInfString(InformationString::getString());
}

void QGame::onClickedRollDice() {
    if(!Game::isEndGame()) {
        Game::onPlayerTurn(*currentPlayer);
        endTurn();
    }
    else
        end();

}

void QGame::onClickedSurrender() {
    if(!Game::isEndGame()) {
        Game::surrenderPlayer(*currentPlayer);
        gameWindow.getPlayersInfo()->update();
    }
    else
        end();
}
