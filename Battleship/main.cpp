#include "mainwindow.h"
#include "startwindow.h"
#include "grid.h"
#include "placeships.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();

    StartWindow start;
    start.show();

//    Grid gameboard;
//    gameboard.show();

//    PlaceShips player;
//    player.show();


    return a.exec();
}
