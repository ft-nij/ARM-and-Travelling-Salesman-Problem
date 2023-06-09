/********************************************************************************
** Form generated from reading UI file 'catalog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATALOG_H
#define UI_CATALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Catalog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboType;
    QComboBox *comboProduct;
    QPushButton *btnProduct;
    QLabel *label_2;

    void setupUi(QDialog *Catalog)
    {
        if (Catalog->objectName().isEmpty())
            Catalog->setObjectName(QString::fromUtf8("Catalog"));
        Catalog->resize(472, 205);
        verticalLayoutWidget = new QWidget(Catalog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 431, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        comboType = new QComboBox(verticalLayoutWidget);
        comboType->setObjectName(QString::fromUtf8("comboType"));

        verticalLayout->addWidget(comboType);

        comboProduct = new QComboBox(verticalLayoutWidget);
        comboProduct->setObjectName(QString::fromUtf8("comboProduct"));

        verticalLayout->addWidget(comboProduct);

        btnProduct = new QPushButton(verticalLayoutWidget);
        btnProduct->setObjectName(QString::fromUtf8("btnProduct"));

        verticalLayout->addWidget(btnProduct);

        label_2 = new QLabel(Catalog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 451, 181));
        label_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/ftsyb/Downloads/imgonline-com-ua-Resize-joefOmnvrd.jpg")));
        label_2->raise();
        verticalLayoutWidget->raise();

        retranslateUi(Catalog);

        QMetaObject::connectSlotsByName(Catalog);
    } // setupUi

    void retranslateUi(QDialog *Catalog)
    {
        Catalog->setWindowTitle(QApplication::translate("Catalog", "Dialog", nullptr));
        label->setText(QApplication::translate("Catalog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600; font-style:italic;\">\320\224\320\276\321\201\321\202\321\203\320\277\320\275\321\213\320\265 \321\202\320\276\320\262\320\260\321\200\321\213</span></p></body></html>", nullptr));
        btnProduct->setText(QApplication::translate("Catalog", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Catalog: public Ui_Catalog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATALOG_H
