#include "QBuyCompanyWindow.h"

QBuyCompanyWindow::QBuyCompanyWindow(QString title, QString text, QString textButton1, QString textButton2) : QWidget(),
    layout(this), layoutButton(this), label(text, this),
    pushButton1(textButton1, this), pushButton2(textButton2, this) {
    setWindowTitle(title);
    setMinimumSize(300, 50);

    layoutButton.addWidget(&pushButton1);
    layoutButton.addWidget(&pushButton2);

    layout.addWidget(&label);
    layout.addLayout(&layoutButton);
}

QPushButton* QBuyCompanyWindow::getPushButton1() {
    return &pushButton1;
}

QPushButton* QBuyCompanyWindow::getPushButton2() {
    return &pushButton2;
}

