#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

class QBuyCompanyWindow : public QWidget {
    Q_OBJECT

    QVBoxLayout layout;
    QHBoxLayout layoutButton;
    QLabel label;
    QPushButton pushButton1;
    QPushButton pushButton2;

public:
    QBuyCompanyWindow(QString title, QString text, QString textButton1, QString textButton2);
    QPushButton* getPushButton1();
    QPushButton* getPushButton2();
};
