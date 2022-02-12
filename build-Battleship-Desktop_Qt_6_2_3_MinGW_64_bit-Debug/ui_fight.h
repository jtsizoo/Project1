/********************************************************************************
** Form generated from reading UI file 'fight.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIGHT_H
#define UI_FIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "grid.h"

QT_BEGIN_NAMESPACE

class Ui_fight
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *fight_verticalLayout;
    QHBoxLayout *grid_horizontalLayout;
    QGroupBox *you_groupBox;
    QVBoxLayout *verticalLayout;
    Grid *you_grid;
    QGroupBox *opponent_groupBox;
    QVBoxLayout *verticalLayout_2;
    Grid *opponent_grid;
    QHBoxLayout *fire_horizontalLayout;
    QLabel *coord_label;
    QComboBox *col_comboBox;
    QComboBox *row_comboBox;
    QPushButton *pushButton;
    QHBoxLayout *text_horizontalLayout;
    QLabel *turn_label;
    QLabel *playerTurn_label;
    QSpacerItem *horizontalSpacer;
    QLabel *status_label;
    QLabel *update_label;

    void setupUi(QWidget *fight)
    {
        if (fight->objectName().isEmpty())
            fight->setObjectName(QString::fromUtf8("fight"));
        fight->resize(684, 508);
        verticalLayout_4 = new QVBoxLayout(fight);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        fight_verticalLayout = new QVBoxLayout();
        fight_verticalLayout->setObjectName(QString::fromUtf8("fight_verticalLayout"));
        grid_horizontalLayout = new QHBoxLayout();
        grid_horizontalLayout->setObjectName(QString::fromUtf8("grid_horizontalLayout"));
        you_groupBox = new QGroupBox(fight);
        you_groupBox->setObjectName(QString::fromUtf8("you_groupBox"));
        verticalLayout = new QVBoxLayout(you_groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        you_grid = new Grid(you_groupBox);
        you_grid->setObjectName(QString::fromUtf8("you_grid"));

        verticalLayout->addWidget(you_grid);


        grid_horizontalLayout->addWidget(you_groupBox);

        opponent_groupBox = new QGroupBox(fight);
        opponent_groupBox->setObjectName(QString::fromUtf8("opponent_groupBox"));
        verticalLayout_2 = new QVBoxLayout(opponent_groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        opponent_grid = new Grid(opponent_groupBox);
        opponent_grid->setObjectName(QString::fromUtf8("opponent_grid"));

        verticalLayout_2->addWidget(opponent_grid);


        grid_horizontalLayout->addWidget(opponent_groupBox);


        fight_verticalLayout->addLayout(grid_horizontalLayout);

        fire_horizontalLayout = new QHBoxLayout();
        fire_horizontalLayout->setObjectName(QString::fromUtf8("fire_horizontalLayout"));
        coord_label = new QLabel(fight);
        coord_label->setObjectName(QString::fromUtf8("coord_label"));

        fire_horizontalLayout->addWidget(coord_label);

        col_comboBox = new QComboBox(fight);
        col_comboBox->setObjectName(QString::fromUtf8("col_comboBox"));

        fire_horizontalLayout->addWidget(col_comboBox);

        row_comboBox = new QComboBox(fight);
        row_comboBox->setObjectName(QString::fromUtf8("row_comboBox"));

        fire_horizontalLayout->addWidget(row_comboBox);

        pushButton = new QPushButton(fight);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        fire_horizontalLayout->addWidget(pushButton);


        fight_verticalLayout->addLayout(fire_horizontalLayout);

        text_horizontalLayout = new QHBoxLayout();
        text_horizontalLayout->setObjectName(QString::fromUtf8("text_horizontalLayout"));
        turn_label = new QLabel(fight);
        turn_label->setObjectName(QString::fromUtf8("turn_label"));

        text_horizontalLayout->addWidget(turn_label);

        playerTurn_label = new QLabel(fight);
        playerTurn_label->setObjectName(QString::fromUtf8("playerTurn_label"));

        text_horizontalLayout->addWidget(playerTurn_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        text_horizontalLayout->addItem(horizontalSpacer);

        status_label = new QLabel(fight);
        status_label->setObjectName(QString::fromUtf8("status_label"));

        text_horizontalLayout->addWidget(status_label);

        update_label = new QLabel(fight);
        update_label->setObjectName(QString::fromUtf8("update_label"));

        text_horizontalLayout->addWidget(update_label);


        fight_verticalLayout->addLayout(text_horizontalLayout);

        fight_verticalLayout->setStretch(0, 1);

        verticalLayout_4->addLayout(fight_verticalLayout);


        retranslateUi(fight);

        QMetaObject::connectSlotsByName(fight);
    } // setupUi

    void retranslateUi(QWidget *fight)
    {
        fight->setWindowTitle(QCoreApplication::translate("fight", "Form", nullptr));
        you_groupBox->setTitle(QCoreApplication::translate("fight", "You:", nullptr));
        opponent_groupBox->setTitle(QCoreApplication::translate("fight", "Opponent:", nullptr));
        coord_label->setText(QCoreApplication::translate("fight", "Choose Coordinant:", nullptr));
        pushButton->setText(QCoreApplication::translate("fight", "FIRE!", nullptr));
        turn_label->setText(QCoreApplication::translate("fight", "Turn:", nullptr));
        playerTurn_label->setText(QCoreApplication::translate("fight", "Player #", nullptr));
        status_label->setText(QCoreApplication::translate("fight", "Status:", nullptr));
        update_label->setText(QCoreApplication::translate("fight", "update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fight: public Ui_fight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIGHT_H
