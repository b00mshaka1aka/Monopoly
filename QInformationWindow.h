#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class QInformationWindow : public QWidget {
    Q_OBJECT

    QVBoxLayout layout;
    QLabel label;
    QPushButton pushButton;

public:
    QInformationWindow(QString title, QString text, QString buttonText);
    QPushButton* getPushButton();
};

