#include "QMainMenu.h"

QMainMenu::QMainMenu(QWidget* parent) : mainMenuWidget(), logo(&mainMenuWidget),
    startGame("Начать игру", &mainMenuWidget), leaveGame("Выйти из игры", &mainMenuWidget), layout(&mainMenuWidget),
    parentWidget(parent) {

    QPixmap logoPixmap("C:\\Users\\Shish\\Documents\\QtProjects\\Monopoly\\Image\\Logo.png");
    logoPixmap = logoPixmap.scaled(500, 500, Qt::KeepAspectRatio);
    logo.setPixmap(logoPixmap);

    layout.addWidget(&logo);
    layout.addWidget(&startGame);
    layout.addWidget(&leaveGame);

    connect(&startGame, &QPushButton::clicked, this, &QMainMenu::onClickedStartGame);
    connect(&leaveGame, &QPushButton::clicked, &mainMenuWidget, &QWidget::close);
}

void QMainMenu::show() {
    mainMenuWidget.show();
}

void QMainMenu::onClickedStartGame() {
    game = new QGame(parentWidget);
    game->start();

    mainMenuWidget.close();
}
