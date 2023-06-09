/********************************************************************************
** Form generated from reading UI file 'sotrudnik.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOTRUDNIK_H
#define UI_SOTRUDNIK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sotrudnik
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *BDButton;
    QPushButton *btnOrders;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Sotrudnik)
    {
        if (Sotrudnik->objectName().isEmpty())
            Sotrudnik->setObjectName(QString::fromUtf8("Sotrudnik"));
        Sotrudnik->resize(532, 348);
        groupBox = new QGroupBox(Sotrudnik);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 30, 451, 261));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(18);
        groupBox->setFont(font);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 80, 441, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        BDButton = new QPushButton(layoutWidget);
        BDButton->setObjectName(QString::fromUtf8("BDButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(14);
        BDButton->setFont(font1);

        verticalLayout->addWidget(BDButton);

        btnOrders = new QPushButton(layoutWidget);
        btnOrders->setObjectName(QString::fromUtf8("btnOrders"));
        btnOrders->setFont(font1);

        verticalLayout->addWidget(btnOrders);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font1);

        verticalLayout->addWidget(pushButton);

        label = new QLabel(Sotrudnik);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(4, 5, 521, 331));
        label->setPixmap(QPixmap(QString::fromUtf8("C:/Users/ftsyb/Downloads/imgonline-com-ua-Resize-joefOmnvrd.jpg")));
        label_2 = new QLabel(Sotrudnik);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(460, 10, 81, 61));
        label_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/ftsyb/Downloads/\320\274\320\270\320\275\320\270 \320\273\320\276\320\263\320\276.jpg")));
        label->raise();
        groupBox->raise();
        label_2->raise();

        retranslateUi(Sotrudnik);

        QMetaObject::connectSlotsByName(Sotrudnik);
    } // setupUi

    void retranslateUi(QWidget *Sotrudnik)
    {
        Sotrudnik->setWindowTitle(QApplication::translate("Sotrudnik", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("Sotrudnik", "\320\234\320\265\320\275\321\216", nullptr));
        BDButton->setText(QApplication::translate("Sotrudnik", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\321\213\321\205 \320\277\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\320\265\320\271", nullptr));
        btnOrders->setText(QApplication::translate("Sotrudnik", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\321\213\321\205 \320\267\320\260\320\272\320\260\320\267\320\276\320\262", nullptr));
        pushButton->setText(QApplication::translate("Sotrudnik", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \320\275\320\260\320\273\320\270\321\207\320\270\320\265 \321\202\320\276\320\262\320\260\321\200\320\276\320\262", nullptr));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Sotrudnik: public Ui_Sotrudnik {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOTRUDNIK_H
