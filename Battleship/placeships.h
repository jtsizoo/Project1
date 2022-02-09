#ifndef PLACESHIPS_H
#define PLACESHIPS_H

#include <QWidget>

namespace Ui {
class PlaceShips;
}

class PlaceShips : public QWidget
{
    Q_OBJECT

public:
    explicit PlaceShips(QWidget *parent = nullptr);
    ~PlaceShips();

    void setShipNumber(int num);

private slots:
    void on_done_pushButton_clicked();

private:
    Ui::PlaceShips *ui;

    int shipNumber;

    void displayShips();
    void initComboBoxes();

signals:
    void done(bool show);
};

#endif // PLACESHIPS_H
