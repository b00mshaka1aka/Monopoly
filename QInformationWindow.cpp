#include "QInformationWindow.h"

QInformationWindow::QInformationWindow(QString title, QString text, QString buttonText) : QWidget(), layout(this),
    label(text, this), pushButton(buttonText, this) {
    setWindowTitle(title);
    setMinimumSize(300, 50);

    layout.addWidget(&label);
    layout.addWidget(&pushButton);

    QObject::connect(&pushButton, SIGNAL(clicked()), this, SLOT(close()));
}

QPushButton* QInformationWindow::getPushButton() {
    return &pushButton;
}
