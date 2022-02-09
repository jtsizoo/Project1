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

    void setUpdateText(QString update);
    void setPlayerText(QString player);

private:
    Ui::fight *ui;

    void initComboBoxes();
};

#endif // FIGHT_H
