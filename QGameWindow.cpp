#include "QGameWindow.h"

QGameWindow::QGameWindow(QVector<QPlayer*>* ptrPlayersVector, QWidget* parent) : gameWidget(parent), infoWidget(parent),
    playersInfo(ptrPlayersVector, parent), layout(&infoWidget),
    buttonLayout(&infoWidget),  gameboardPixmap("C:\\Users\\Shish\\Documents\\QtProjects\\Monopoly\\Image\\Gameboard.png"),
    gameboard(&gameWidget), infString(&gameWidget), surrender("Сдаться", &infoWidget),
    rollDice("Бросить кубики", &infoWidget), endGame("Выйти из игры", &infoWidget) {
    parent->show();

    infoWidget.setGeometry(565, 8, gameboardPixmap.width() - 565, gameboardPixmap.height() - 8);

    gameboard.setPixmap(gameboardPixmap);
    gameboard.setFixedSize(gameboardPixmap.size());
    gameWidget.setFixedSize(gameboardPixmap.size());

    infString.setText("Информационная строка");

    buttonLayout.addWidget(&endGame);
    buttonLayout.addWidget(&surrender);

    layout.addWidget(playersInfo.getWidget());
    layout.addWidget(&infString);
    layout.addWidget(&rollDice);
    layout.addLayout(&buttonLayout);

    parent->setFixedSize(gameboardPixmap.size());
}

void QGameWindow::show() {
    gameWidget.show();
    infoWidget.show();
    playersInfo.getWidget()->show();
}

void QGameWindow::setTextInfString(QString text) {
    infString.setText(text);
}

QPushButton* QGameWindow::getSurrenderButton() {
    return &surrender;
}

QPushButton* QGameWindow::getEndGameButton() {
    return &endGame;
}

QPushButton* QGameWindow::getRollDiceButton() {
    return &rollDice;
}

QPlayersInfo* QGameWindow::getPlayersInfo() {
    return &playersInfo;
}
