#include "playerwindow.h"
#include "ui_playerwindow.h"

PlayerWindow::PlayerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayerWindow)
{
    ui->setupUi(this);

    // show ship select and hide fight
    showPlaceShips(true);

    // connect signal and slots
    connect(ui->place_ships, SIGNAL(done(bool)), this, SLOT(OnPlayerDone(bool)));
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
    // update label with player's identity
    ui->player_label->setText( QString("Player %1").arg(player) );
}

void PlayerWindow::showPlaceShips(bool show)
{
    // only one widget can be visible at a time
    ui->place_ships->setVisible(show);
    ui->player_fight->setVisible(!show);
}

void PlayerWindow::OnPlayerDone(bool show)
{
    emit playerDone(show);
}
