/********************************************************************************
** Form generated from reading UI file 'auto.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTO_H
#define UI_AUTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Auto
{
public:
    QGroupBox *groupBox;
    QPushButton *AutoButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *login;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *password;
    QLabel *label_4;
    QLabel *label_3;

    void setupUi(QWidget *Auto)
    {
        if (Auto->objectName().isEmpty())
            Auto->setObjectName(QString::fromUtf8("Auto"));
        Auto->resize(550, 410);
        groupBox = new QGroupBox(Auto);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, 40, 461, 331));
        QFont font;
        font.setPointSize(16);
        groupBox->setFont(font);
        AutoButton = new QPushButton(groupBox);
        AutoButton->setObjectName(QString::fromUtf8("AutoButton"));
        AutoButton->setGeometry(QRect(180, 270, 93, 41));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 80, 401, 173));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        login = new QLineEdit(layoutWidget);
        login->setObjectName(QString::fromUtf8("login"));

        horizontalLayout->addWidget(login);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        password = new QLineEdit(layoutWidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(password);


        verticalLayout->addLayout(horizontalLayout_2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(410, 10, 61, 71));
        label_4->setPixmap(QPixmap(QString::fromUtf8("C:/Users/ftsyb/Downloads/\320\274\320\270\320\275\320\270 \320\273\320\276\320\263\320\276.jpg")));
        label_3 = new QLabel(Auto);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 531, 391));
        label_3->setPixmap(QPixmap(QString::fromUtf8("C:/Users/ftsyb/Downloads/imgonline-com-ua-Resize-joefOmnvrd.jpg")));
        label_3->raise();
        groupBox->raise();

        retranslateUi(Auto);

        QMetaObject::connectSlotsByName(Auto);
    } // setupUi

    void retranslateUi(QWidget *Auto)
    {
        Auto->setWindowTitle(QApplication::translate("Auto", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("Auto", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        AutoButton->setText(QApplication::translate("Auto", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        label->setText(QApplication::translate("Auto", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label_2->setText(QApplication::translate("Auto", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        label_4->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Auto: public Ui_Auto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTO_H
