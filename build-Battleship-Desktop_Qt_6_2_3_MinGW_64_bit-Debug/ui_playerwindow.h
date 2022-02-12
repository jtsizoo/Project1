/********************************************************************************
** Form generated from reading UI file 'playerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERWINDOW_H
#define UI_PLAYERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "fight.h"
#include "placeships.h"

QT_BEGIN_NAMESPACE

class Ui_PlayerWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *player_label;
    PlaceShips *place_ships;
    QLabel *wait_label;
    fight *player_fight;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlayerWindow)
    {
        if (PlayerWindow->objectName().isEmpty())
            PlayerWindow->setObjectName(QString::fromUtf8("PlayerWindow"));
        PlayerWindow->resize(800, 600);
        centralwidget = new QWidget(PlayerWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        player_label = new QLabel(centralwidget);
        player_label->setObjectName(QString::fromUtf8("player_label"));
        player_label->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(player_label, 0, Qt::AlignHCenter);

        place_ships = new PlaceShips(centralwidget);
        place_ships->setObjectName(QString::fromUtf8("place_ships"));

        verticalLayout->addWidget(place_ships);

        wait_label = new QLabel(centralwidget);
        wait_label->setObjectName(QString::fromUtf8("wait_label"));

        verticalLayout->addWidget(wait_label, 0, Qt::AlignHCenter);

        player_fight = new fight(centralwidget);
        player_fight->setObjectName(QString::fromUtf8("player_fight"));

        verticalLayout->addWidget(player_fight);

        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(3, 1);
        PlayerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlayerWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        PlayerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PlayerWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PlayerWindow->setStatusBar(statusbar);

        retranslateUi(PlayerWindow);

        QMetaObject::connectSlotsByName(PlayerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PlayerWindow)
    {
        PlayerWindow->setWindowTitle(QCoreApplication::translate("PlayerWindow", "MainWindow", nullptr));
        player_label->setText(QCoreApplication::translate("PlayerWindow", "Player #", nullptr));
        wait_label->setText(QCoreApplication::translate("PlayerWindow", "Waiting for opponent...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerWindow: public Ui_PlayerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERWINDOW_H
