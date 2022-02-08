#include "fight.h"
#include "ui_fight.h"

fight::fight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fight)
{
    ui->setupUi(this);
}

fight::~fight()
{
    delete ui;
}
