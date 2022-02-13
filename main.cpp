#include "startwindow.h"
#include "grid.h"
#include "placeships.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // start Battleship game
    StartWindow start;
    start.show();

    return a.exec();
}
