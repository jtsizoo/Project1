#include "playerwindow.h"
#include "ui_playerwindow.h"

PlayerWindow::PlayerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayerWindow)
{
    ui->setupUi(this);

    // setup UI
    showPlaceShips(true);
    ui->wait_label->setVisible(false);

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

    // reinitialize
    ui->wait_label->setVisible(false);
}

void PlayerWindow::OnPlayerDone(bool show)
{
    ui->place_ships->setDisabled(true);
    ui->wait_label->setVisible(true);
    emit playerDone(show);
}
