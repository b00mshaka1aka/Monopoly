QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Chance.cpp \
    Company.cpp \
    Game.cpp \
    InformationString.cpp \
    Player.cpp \
    PlayerInterface.cpp \
    QBuyCompanyWindow.cpp \
    QChance.cpp \
    QCompany.cpp \
    QGame.cpp \
    QGameWindow.cpp \
    QInformationWindow.cpp \
    QMainMenu.cpp \
    QPlayer.cpp \
    QPlayerInterface.cpp \
    QPlayersInfoWindow.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Chance.h \
    Company.h \
    Field.h \
    Game.h \
    InformationString.h \
    LargeFields.h \
    MainWindow.h \
    Player.h \
    PlayerInterface.h \
    QBuyCompanyWindow.h \
    QChance.h \
    QCompany.h \
    QGame.h \
    QGameWindow.h \
    QInfWindows.h \
    QInformationWindow.h \
    QLargeFields.h \
    QMainMenu.h \
    QPlayer.h \
    QPlayerInterface.h \
    QPlayersInfo.h \
    QPlayersInfoWindow.h \
    Random.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS +=
