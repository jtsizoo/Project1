/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *ship_horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *ships_groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *ship1_radioButton;
    QRadioButton *ship2_radioButton;
    QRadioButton *ship3_radioButton;
    QRadioButton *ship4_radioButton;
    QRadioButton *ship5_radioButton;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *start_horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *start_pushButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QString::fromUtf8("StartWindow"));
        StartWindow->resize(800, 600);
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        ship_horizontalLayout = new QHBoxLayout();
        ship_horizontalLayout->setObjectName(QString::fromUtf8("ship_horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ship_horizontalLayout->addItem(horizontalSpacer_4);

        ships_groupBox = new QGroupBox(centralwidget);
        ships_groupBox->setObjectName(QString::fromUtf8("ships_groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ships_groupBox->sizePolicy().hasHeightForWidth());
        ships_groupBox->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(ships_groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ship1_radioButton = new QRadioButton(ships_groupBox);
        ship1_radioButton->setObjectName(QString::fromUtf8("ship1_radioButton"));

        verticalLayout_2->addWidget(ship1_radioButton);

        ship2_radioButton = new QRadioButton(ships_groupBox);
        ship2_radioButton->setObjectName(QString::fromUtf8("ship2_radioButton"));

        verticalLayout_2->addWidget(ship2_radioButton);

        ship3_radioButton = new QRadioButton(ships_groupBox);
        ship3_radioButton->setObjectName(QString::fromUtf8("ship3_radioButton"));

        verticalLayout_2->addWidget(ship3_radioButton);

        ship4_radioButton = new QRadioButton(ships_groupBox);
        ship4_radioButton->setObjectName(QString::fromUtf8("ship4_radioButton"));

        verticalLayout_2->addWidget(ship4_radioButton);

        ship5_radioButton = new QRadioButton(ships_groupBox);
        ship5_radioButton->setObjectName(QString::fromUtf8("ship5_radioButton"));

        verticalLayout_2->addWidget(ship5_radioButton);


        ship_horizontalLayout->addWidget(ships_groupBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ship_horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(ship_horizontalLayout);

        start_horizontalLayout = new QHBoxLayout();
        start_horizontalLayout->setObjectName(QString::fromUtf8("start_horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        start_horizontalLayout->addItem(horizontalSpacer);

        start_pushButton = new QPushButton(centralwidget);
        start_pushButton->setObjectName(QString::fromUtf8("start_pushButton"));

        start_horizontalLayout->addWidget(start_pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        start_horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(start_horizontalLayout);

        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        StartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        StartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StartWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StartWindow->setStatusBar(statusbar);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "MainWindow", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("StartWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:700;\">BATTLESHIP</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">2-Player</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:"
                        "0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~</p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        ships_groupBox->setTitle(QCoreApplication::translate("StartWindow", "Choose your ships:", nullptr));
        ship1_radioButton->setText(QCoreApplication::translate("StartWindow", "1 ship (1x1)", nullptr));
        ship2_radioButton->setText(QCoreApplication::translate("StartWindow", "2 ships (1x1, 1x2)", nullptr));
        ship3_radioButton->setText(QCoreApplication::translate("StartWindow", "3 ships (1x1, 1x2, 1x3)", nullptr));
        ship4_radioButton->setText(QCoreApplication::translate("StartWindow", "4 ships (1x1, 1x2, 1x3, 1x4)", nullptr));
        ship5_radioButton->setText(QCoreApplication::translate("StartWindow", "5 ships (1x1, 1x2, 1x3, 1x4, 1x5)", nullptr));
        start_pushButton->setText(QCoreApplication::translate("StartWindow", "START", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
