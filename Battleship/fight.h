#ifndef FIGHT_H
#define FIGHT_H

#include <QWidget>

namespace Ui {
class fight;
}

class fight : public QWidget
{
    Q_OBJECT

public:
    explicit fight(QWidget *parent = nullptr);
    ~fight();

private:
    Ui::fight *ui;
};

#endif // FIGHT_H
