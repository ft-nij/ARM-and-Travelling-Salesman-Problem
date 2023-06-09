/********************************************************************************
** Form generated from reading UI file 'bd.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BD_H
#define UI_BD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BD
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QPushButton *AddButton;
    QPushButton *DeleteButton;

    void setupUi(QWidget *BD)
    {
        if (BD->objectName().isEmpty())
            BD->setObjectName(QString::fromUtf8("BD"));
        BD->resize(557, 491);
        layoutWidget = new QWidget(BD);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 11, 531, 471));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEnabled(true);

        verticalLayout_2->addWidget(tableView);

        AddButton = new QPushButton(layoutWidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setEnabled(true);
        QFont font;
        font.setPointSize(16);
        AddButton->setFont(font);

        verticalLayout_2->addWidget(AddButton);

        DeleteButton = new QPushButton(layoutWidget);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));
        DeleteButton->setEnabled(true);
        DeleteButton->setFont(font);

        verticalLayout_2->addWidget(DeleteButton);

        AddButton->raise();
        DeleteButton->raise();
        tableView->raise();

        retranslateUi(BD);

        QMetaObject::connectSlotsByName(BD);
    } // setupUi

    void retranslateUi(QWidget *BD)
    {
        BD->setWindowTitle(QApplication::translate("BD", "Form", nullptr));
        AddButton->setText(QApplication::translate("BD", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        DeleteButton->setText(QApplication::translate("BD", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BD: public Ui_BD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BD_H
