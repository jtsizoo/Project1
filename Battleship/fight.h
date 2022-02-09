#ifndef FIGHT_H
#define FIGHT_H

#include <QWidget>
#include <QString>

namespace Ui {
class fight;
}

class fight : public QWidget
{
    Q_OBJECT

public:
    explicit fight(QWidget *parent = nullptr);
    ~fight();

    void setUpdateText(QString update); // change the status of the game
    void setPlayerText(QString player); // change to current player

private:
    Ui::fight *ui;

    void initComboBoxes();  // add coordinants to combo boxes
};

#endif // FIGHT_H
