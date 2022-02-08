#include "playerwindow.h"
#include "ui_playerwindow.h"

PlayerWindow::PlayerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayerWindow)
{
    ui->setupUi(this);
}

PlayerWindow::~PlayerWindow()
{
    delete ui;
}

void PlayerWindow::setShipNumber(int ship)
{
    // pass to the PlaceShips widget
    ui->place_ships->setShipNumber(ship);
}

void PlayerWindow::setPlayer(QString player)
{
    ui->player_label->setText( QString("Player %1").arg(player) );
}
