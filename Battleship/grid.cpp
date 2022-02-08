#include "grid.h"
#include "ui_grid.h"

Grid::Grid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Grid)
{
    ui->setupUi(this);

    init();
}

Grid::~Grid()
{
    delete ui;
}

void Grid::init()
{
    // set column  size
    int col = ui->gameGrid_tableWidget->columnCount();
    for(int i=0; i<col; i++)
    {
        ui->gameGrid_tableWidget->setColumnWidth(i,50);
    }
    // set row size
    int row = ui->gameGrid_tableWidget->rowCount();
    for(int i=0; i<row; i++)
    {
        ui->gameGrid_tableWidget->setRowHeight(i,50);
    }

    // add Item to each cell and color it blue
    for(int r=0; r<row; r++)
    {
        for(int c=0;c<col;c++)
        {
            ui->gameGrid_tableWidget->setItem(r, c, new QTableWidgetItem);
            setEmpty(r,c);
        }
    }

    // user canot edit grid
    ui->gameGrid_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Grid::setEmpty(int row, int col)
{
    // change cell to blue
    ui->gameGrid_tableWidget->item(row, col)->setBackground(Qt::blue);
}

void Grid::setShip(int row, int col)
{
    // change cell to gray
    ui->gameGrid_tableWidget->item(row, col)->setBackground(Qt::gray);
}

void Grid::setMiss(int row, int col)
{
    // change cell to white
    ui->gameGrid_tableWidget->item(row, col)->setBackground(Qt::white);
}

void Grid::setHit(int row, int col)
{
    // change cell to red
    ui->gameGrid_tableWidget->item(row, col)->setBackground(Qt::red);
}

void Grid::cleanBoard()
{
    // get size of grid
    int col = ui->gameGrid_tableWidget->columnCount();
    int row = ui->gameGrid_tableWidget->rowCount();

    // set every cell to blue
    for(int r=0; r<row; r++)
    {
        for(int c=0;c<col;c++)
        {
            setEmpty(r,c);
        }
    }
}
