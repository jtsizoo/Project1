#include "placeships.h"
#include "ui_placeships.h"

PlaceShips::PlaceShips(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaceShips)
{
    ui->setupUi(this);

    // initialize variables
    shipNumber = 0;

    // setup UI
    displayShips();
    initComboBoxes();
}

PlaceShips::~PlaceShips()
{
    delete ui;
}

void PlaceShips::initComboBoxes()
{
    // convinience
    QComboBox * col = ui->col_comboBox;
    QComboBox * row = ui->row_comboBox;

    // initialize
    col->clear();
    row->clear();

    // fill columns (A-J)
    col->insertItem(0, "A");
    col->insertItem(1, "B");
    col->insertItem(2, "C");
    col->insertItem(3, "D");
    col->insertItem(4, "E");
    col->insertItem(5, "F");
    col->insertItem(6, "G");
    col->insertItem(7, "H");
    col->insertItem(8, "I");
    col->insertItem(9, "J");

    // fill rows (1-10)
    row->insertItem(0, "1");
    row->insertItem(1, "2");
    row->insertItem(2, "3");
    row->insertItem(3, "4");
    row->insertItem(4, "5");
    row->insertItem(5, "6");
    row->insertItem(6, "7");
    row->insertItem(7, "8");
    row->insertItem(8, "9");
    row->insertItem(9, "10");
}

void PlaceShips::setShipNumber(int num)
{
    // check/set minimum ship count
    if(num < 1)
    {
        num = 1;
    }
    // check/set maximum ship count
    if(num > 5)
    {
        num = 5;
    }

    shipNumber = num;
}

void PlaceShips::displayShips()
{
    // initialize by hiding all ship radio buttons
    ui->ship1_radioButton->setVisible(false);
    ui->ship2_radioButton->setVisible(false);
    ui->ship3_radioButton->setVisible(false);
    ui->ship4_radioButton->setVisible(false);
    ui->ship5_radioButton->setVisible(false);

    // only show buttons based on the number of allowed ships
    if(shipNumber == 5)
    {
        ui->ship1_radioButton->setVisible(true);
        ui->ship2_radioButton->setVisible(true);
        ui->ship3_radioButton->setVisible(true);
        ui->ship4_radioButton->setVisible(true);
        ui->ship5_radioButton->setVisible(true);
    }
    else if(shipNumber == 4)
    {
        ui->ship1_radioButton->setVisible(true);
        ui->ship2_radioButton->setVisible(true);
        ui->ship3_radioButton->setVisible(true);
        ui->ship4_radioButton->setVisible(true);
    }
    else if(shipNumber == 3)
    {
        ui->ship1_radioButton->setVisible(true);
        ui->ship2_radioButton->setVisible(true);
        ui->ship3_radioButton->setVisible(true);
    }
    else if(shipNumber == 2)
    {
        ui->ship1_radioButton->setVisible(true);
        ui->ship2_radioButton->setVisible(true);
    }
    else if(shipNumber == 1)
    {
        ui->ship1_radioButton->setVisible(true);
    }
}
