/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Info
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *showInfo;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QDialog *Info)
    {
        if (Info->objectName().isEmpty())
            Info->setObjectName(QString::fromUtf8("Info"));
        Info->resize(426, 165);
        verticalLayoutWidget = new QWidget(Info);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 20, 301, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        showInfo = new QLabel(verticalLayoutWidget);
        showInfo->setObjectName(QString::fromUtf8("showInfo"));
        QFont font;
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        showInfo->setFont(font);

        verticalLayout->addWidget(showInfo);

        pushButton = new QPushButton(Info);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 130, 93, 28));
        label_2 = new QLabel(Info);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 411, 151));
        label_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/ftsyb/Downloads/imgonline-com-ua-Resize-joefOmnvrd.jpg")));
        label_2->raise();
        verticalLayoutWidget->raise();
        pushButton->raise();

        retranslateUi(Info);
        QObject::connect(pushButton, SIGNAL(clicked()), Info, SLOT(close()));

        QMetaObject::connectSlotsByName(Info);
    } // setupUi

    void retranslateUi(QDialog *Info)
    {
        Info->setWindowTitle(QApplication::translate("Info", "Dialog", nullptr));
        label->setText(QApplication::translate("Info", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\320\241\321\202\320\260\321\202\321\203\321\201 \320\262\320\260\321\210\320\265\320\263\320\276 \320\267\320\260\320\272\320\260\320\267\320\260</span></p></body></html>", nullptr));
        showInfo->setText(QApplication::translate("Info", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("Info", "OK", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Info: public Ui_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
