#include "MainWindow.h"

#include <QApplication>
#include "QMainMenu.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    QMainMenu mainMenu(&mainWindow);
    mainMenu.show();

    return app.exec();
}
