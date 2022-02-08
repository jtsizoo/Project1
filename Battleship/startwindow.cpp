#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    ui->start_pushButton->setEnabled(false);
    shipSelectStatus = 0;
    shipNumber = 0;
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::startEnable(bool status)
{
    // enable or disable the start button
    ui->start_pushButton->setEnabled(status);
}

bool StartWindow::areShipsSelected()
{
    bool ship;

    // check if any button is checked.
    // If so, set ship to true. Otherwise, set ship to false
    if(ui->ship1_radioButton->isChecked()) ship = true;
    else if(ui->ship2_radioButton->isChecked()) ship = true;
    else if(ui->ship3_radioButton->isChecked()) ship = true;
    else if(ui->ship4_radioButton->isChecked()) ship = true;
    else if(ui->ship5_radioButton->isChecked()) ship = true;
    else ship = false;

    // allow start to be clicked if a ship is selected
    startEnable(ship);

    return(ship);
}

void StartWindow::on_ship1_radioButton_toggled(bool checked)
{
    areShipsSelected();
    if(checked) shipNumber = 1;
}

void StartWindow::on_ship2_radioButton_toggled(bool checked)
{
    areShipsSelected();
    if(checked) shipNumber = 2;
}

void StartWindow::on_ship3_radioButton_toggled(bool checked)
{
    areShipsSelected();
    if(checked) shipNumber = 3;
}

void StartWindow::on_ship4_radioButton_toggled(bool checked)
{
    areShipsSelected();
    if(checked) shipNumber = 4;
}

void StartWindow::on_ship5_radioButton_toggled(bool checked)
{
    areShipsSelected();
    if(checked) shipNumber = 5;
}

void StartWindow::on_start_pushButton_clicked()
{
    // pass the number of ships to the player windows
    player1.setShipNumber(shipNumber);
    player2.setShipNumber(shipNumber);

    // set player numbers for label
    player1.setPlayer("1");
    player2.setPlayer("2");

    // open player 1 and player 2 windows
    player1.show();
    player2.show();

    // close start window
    this->close();
}

