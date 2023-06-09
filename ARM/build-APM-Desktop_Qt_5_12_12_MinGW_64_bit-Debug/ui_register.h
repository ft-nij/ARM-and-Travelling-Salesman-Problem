/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

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

class Ui_Register
{
public:
    QGroupBox *groupBox;
    QPushButton *btnRegister;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *inputSurname;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *inputName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *inputPatronymic;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *inputPhone;
    QPushButton *pushButton;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(602, 520);
        groupBox = new QGroupBox(Register);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(90, 80, 461, 381));
        QFont font;
        font.setPointSize(16);
        groupBox->setFont(font);
        btnRegister = new QPushButton(groupBox);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));
        btnRegister->setGeometry(QRect(60, 330, 331, 31));
        QFont font1;
        font1.setPointSize(10);
        btnRegister->setFont(font1);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 80, 364, 187));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setPointSize(14);
        label->setFont(font2);

        horizontalLayout_4->addWidget(label);

        inputSurname = new QLineEdit(layoutWidget);
        inputSurname->setObjectName(QString::fromUtf8("inputSurname"));

        horizontalLayout_4->addWidget(inputSurname);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        horizontalLayout_3->addWidget(label_2);

        inputName = new QLineEdit(layoutWidget);
        inputName->setObjectName(QString::fromUtf8("inputName"));

        horizontalLayout_3->addWidget(inputName);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        horizontalLayout_2->addWidget(label_3);

        inputPatronymic = new QLineEdit(layoutWidget);
        inputPatronymic->setObjectName(QString::fromUtf8("inputPatronymic"));

        horizontalLayout_2->addWidget(inputPatronymic);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        horizontalLayout->addWidget(label_4);

        inputPhone = new QLineEdit(layoutWidget);
        inputPhone->setObjectName(QString::fromUtf8("inputPhone"));

        horizontalLayout->addWidget(inputPhone);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 290, 391, 28));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(11);
        pushButton->setFont(font3);
        label_5 = new QLabel(Register);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 0, 581, 521));
        label_5->setPixmap(QPixmap(QString::fromUtf8("C:/Users/ftsyb/Downloads/imgonline-com-ua-Resize-joefOmnvrd.jpg")));
        label_6 = new QLabel(Register);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(480, 20, 111, 121));
        label_6->setPixmap(QPixmap(QString::fromUtf8("C:/Users/ftsyb/Downloads/\320\274\320\260\320\273 \320\273\320\276\320\263\320\276.jpg")));
        label_5->raise();
        groupBox->raise();
        label_6->raise();

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("Register", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\320\265 \320\275\320\265\320\261\320\276\320\273\321\214\321\210\321\203\321\216 \320\260\320\275\320\272\320\265\321\202\321\203", nullptr));
        btnRegister->setText(QApplication::translate("Register", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\321\202\320\260\321\203\321\202\321\201 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        label->setText(QApplication::translate("Register", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_2->setText(QApplication::translate("Register", "\320\230\320\274\321\217", nullptr));
        label_3->setText(QApplication::translate("Register", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_4->setText(QApplication::translate("Register", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        pushButton->setText(QApplication::translate("Register", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200\321\203 \320\272\320\260\321\202\320\260\320\273\320\276\320\263\320\260 \321\202\320\276\320\262\320\260\321\200\320\276\320\262\320\276\320\262", nullptr));
        label_5->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
