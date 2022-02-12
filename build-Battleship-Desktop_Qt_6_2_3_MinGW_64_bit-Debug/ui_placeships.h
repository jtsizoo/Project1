/********************************************************************************
** Form generated from reading UI file 'placeships.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLACESHIPS_H
#define UI_PLACESHIPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "grid.h"

QT_BEGIN_NAMESPACE

class Ui_PlaceShips
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *select_groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *ship1_radioButton;
    QRadioButton *ship2_radioButton;
    QRadioButton *ship3_radioButton;
    QRadioButton *ship4_radioButton;
    QRadioButton *ship5_radioButton;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *col_comboBox;
    QComboBox *row_comboBox;
    QComboBox *direction_comboBox;
    QPushButton *place_pushButton;
    QSpacerItem *verticalSpacer;
    QGroupBox *place_groupBox;
    QVBoxLayout *verticalLayout;
    Grid *board_Grid;
    QPushButton *done_pushButton;

    void setupUi(QWidget *PlaceShips)
    {
        if (PlaceShips->objectName().isEmpty())
            PlaceShips->setObjectName(QString::fromUtf8("PlaceShips"));
        PlaceShips->resize(546, 431);
        verticalLayout_4 = new QVBoxLayout(PlaceShips);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        select_groupBox = new QGroupBox(PlaceShips);
        select_groupBox->setObjectName(QString::fromUtf8("select_groupBox"));
        verticalLayout_2 = new QVBoxLayout(select_groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ship1_radioButton = new QRadioButton(select_groupBox);
        ship1_radioButton->setObjectName(QString::fromUtf8("ship1_radioButton"));

        verticalLayout_2->addWidget(ship1_radioButton);

        ship2_radioButton = new QRadioButton(select_groupBox);
        ship2_radioButton->setObjectName(QString::fromUtf8("ship2_radioButton"));

        verticalLayout_2->addWidget(ship2_radioButton);

        ship3_radioButton = new QRadioButton(select_groupBox);
        ship3_radioButton->setObjectName(QString::fromUtf8("ship3_radioButton"));

        verticalLayout_2->addWidget(ship3_radioButton);

        ship4_radioButton = new QRadioButton(select_groupBox);
        ship4_radioButton->setObjectName(QString::fromUtf8("ship4_radioButton"));

        verticalLayout_2->addWidget(ship4_radioButton);

        ship5_radioButton = new QRadioButton(select_groupBox);
        ship5_radioButton->setObjectName(QString::fromUtf8("ship5_radioButton"));

        verticalLayout_2->addWidget(ship5_radioButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        col_comboBox = new QComboBox(select_groupBox);
        col_comboBox->setObjectName(QString::fromUtf8("col_comboBox"));

        horizontalLayout_2->addWidget(col_comboBox);

        row_comboBox = new QComboBox(select_groupBox);
        row_comboBox->setObjectName(QString::fromUtf8("row_comboBox"));

        horizontalLayout_2->addWidget(row_comboBox);

        direction_comboBox = new QComboBox(select_groupBox);
        direction_comboBox->setObjectName(QString::fromUtf8("direction_comboBox"));

        horizontalLayout_2->addWidget(direction_comboBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        place_pushButton = new QPushButton(select_groupBox);
        place_pushButton->setObjectName(QString::fromUtf8("place_pushButton"));

        verticalLayout_2->addWidget(place_pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addWidget(select_groupBox);

        place_groupBox = new QGroupBox(PlaceShips);
        place_groupBox->setObjectName(QString::fromUtf8("place_groupBox"));
        verticalLayout = new QVBoxLayout(place_groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        board_Grid = new Grid(place_groupBox);
        board_Grid->setObjectName(QString::fromUtf8("board_Grid"));

        verticalLayout->addWidget(board_Grid);


        horizontalLayout->addWidget(place_groupBox);


        verticalLayout_3->addLayout(horizontalLayout);

        done_pushButton = new QPushButton(PlaceShips);
        done_pushButton->setObjectName(QString::fromUtf8("done_pushButton"));

        verticalLayout_3->addWidget(done_pushButton);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(PlaceShips);

        QMetaObject::connectSlotsByName(PlaceShips);
    } // setupUi

    void retranslateUi(QWidget *PlaceShips)
    {
        PlaceShips->setWindowTitle(QCoreApplication::translate("PlaceShips", "Form", nullptr));
        select_groupBox->setTitle(QCoreApplication::translate("PlaceShips", "Select Ship:", nullptr));
        ship1_radioButton->setText(QCoreApplication::translate("PlaceShips", "1x1", nullptr));
        ship2_radioButton->setText(QCoreApplication::translate("PlaceShips", "1x2", nullptr));
        ship3_radioButton->setText(QCoreApplication::translate("PlaceShips", "1x3", nullptr));
        ship4_radioButton->setText(QCoreApplication::translate("PlaceShips", "1x4", nullptr));
        ship5_radioButton->setText(QCoreApplication::translate("PlaceShips", "1x5", nullptr));
        place_pushButton->setText(QCoreApplication::translate("PlaceShips", "Place", nullptr));
        place_groupBox->setTitle(QCoreApplication::translate("PlaceShips", "Place Ship", nullptr));
        done_pushButton->setText(QCoreApplication::translate("PlaceShips", "DONE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlaceShips: public Ui_PlaceShips {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLACESHIPS_H
