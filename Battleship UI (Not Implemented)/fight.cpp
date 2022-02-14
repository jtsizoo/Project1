#include "fight.h"
#include "ui_fight.h"

fight::fight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fight)
{
    ui->setupUi(this);

    // setup UI
    initComboBoxes();
    setUpdateText("None");
}

fight::~fight()
{
    delete ui;
}

void fight::initComboBoxes()
{
    // convinience pointers
    QComboBox * col = ui->col_comboBox;
    QComboBox * row = ui->row_comboBox;

    // clear out all items
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

void fight::setUpdateText(QString update)
{
    // change text to show status
    ui->update_label->setText(update);

    // status examples:
    //      Player 1 hit at A1
    //      Player 2 missed at B2
    //      Player 1 wins!
    //      Player 2 loses...
}

void fight::setPlayerText(QString player)
{
    // change text to show who's turn it is
    ui->playerTurn_label->setText(player);

    // player text options:
    //      Player 1
    //      Player 2
}
