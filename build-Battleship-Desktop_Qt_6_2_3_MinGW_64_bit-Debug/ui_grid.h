/********************************************************************************
** Form generated from reading UI file 'grid.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRID_H
#define UI_GRID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Grid
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *gameGrid_tableWidget;

    void setupUi(QWidget *Grid)
    {
        if (Grid->objectName().isEmpty())
            Grid->setObjectName(QString::fromUtf8("Grid"));
        Grid->resize(617, 545);
        verticalLayout = new QVBoxLayout(Grid);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gameGrid_tableWidget = new QTableWidget(Grid);
        if (gameGrid_tableWidget->columnCount() < 10)
            gameGrid_tableWidget->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        gameGrid_tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        gameGrid_tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        gameGrid_tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        gameGrid_tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        gameGrid_tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        gameGrid_tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        gameGrid_tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        gameGrid_tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        gameGrid_tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        gameGrid_tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        if (gameGrid_tableWidget->rowCount() < 10)
            gameGrid_tableWidget->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        gameGrid_tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        gameGrid_tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        gameGrid_tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        gameGrid_tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        gameGrid_tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        gameGrid_tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        gameGrid_tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        gameGrid_tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        gameGrid_tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        gameGrid_tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem19);
        gameGrid_tableWidget->setObjectName(QString::fromUtf8("gameGrid_tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gameGrid_tableWidget->sizePolicy().hasHeightForWidth());
        gameGrid_tableWidget->setSizePolicy(sizePolicy);
        gameGrid_tableWidget->setAutoFillBackground(true);
        gameGrid_tableWidget->setShowGrid(true);
        gameGrid_tableWidget->setGridStyle(Qt::SolidLine);
        gameGrid_tableWidget->setCornerButtonEnabled(true);

        verticalLayout->addWidget(gameGrid_tableWidget);


        retranslateUi(Grid);

        QMetaObject::connectSlotsByName(Grid);
    } // setupUi

    void retranslateUi(QWidget *Grid)
    {
        Grid->setWindowTitle(QCoreApplication::translate("Grid", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = gameGrid_tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Grid", "A", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = gameGrid_tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Grid", "B", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = gameGrid_tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Grid", "C", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = gameGrid_tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Grid", "D", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = gameGrid_tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Grid", "E", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = gameGrid_tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Grid", "F", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = gameGrid_tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Grid", "G", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = gameGrid_tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Grid", "H", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = gameGrid_tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Grid", "I", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = gameGrid_tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Grid", "J", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = gameGrid_tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Grid", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = gameGrid_tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Grid", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = gameGrid_tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Grid", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = gameGrid_tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Grid", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = gameGrid_tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Grid", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = gameGrid_tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Grid", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = gameGrid_tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("Grid", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = gameGrid_tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("Grid", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = gameGrid_tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("Grid", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = gameGrid_tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("Grid", "10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Grid: public Ui_Grid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRID_H
