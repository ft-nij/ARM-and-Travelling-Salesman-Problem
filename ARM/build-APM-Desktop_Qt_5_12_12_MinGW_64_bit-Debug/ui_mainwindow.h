/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *SotButton;
    QPushButton *Pokupbutton;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(780, 492);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 50, 441, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 10, 781, 441));
        label_2->setStyleSheet(QString::fromUtf8("background-color : rgb(102, 205, 170)\n"
""));
        label_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/ftsyb/Downloads/imgonline-com-ua-Resize-joefOmnvrd.jpg")));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(330, 280, 441, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        SotButton = new QPushButton(verticalLayoutWidget);
        SotButton->setObjectName(QString::fromUtf8("SotButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(16);
        SotButton->setFont(font1);

        verticalLayout->addWidget(SotButton);

        Pokupbutton = new QPushButton(verticalLayoutWidget);
        Pokupbutton->setObjectName(QString::fromUtf8("Pokupbutton"));
        Pokupbutton->setFont(font1);

        verticalLayout->addWidget(Pokupbutton);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(390, 90, 341, 81));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 10, 321, 431));
        label_4->setPixmap(QPixmap(QString::fromUtf8("C:/Users/ftsyb/Downloads/imgonline-com-ua-Resize-Hqs2dbp6q5JFl.jpg")));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(340, 220, 431, 71));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(14);
        font3.setItalic(true);
        label_5->setFont(font3);
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        label->raise();
        verticalLayoutWidget->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 780, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "FnS", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\234\321\213 \321\200\320\260\320\264\321\213 \320\277\321\200\320\270\320\262\320\265\321\202\321\201\321\202\320\262\320\276\320\262\320\260\321\202\321\214 \320\262\320\260\321\201 \320\262 \320\274\320\260\320\263\320\260\320\267\320\270\320\275\320\265", nullptr));
        label_2->setText(QString());
        SotButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272", nullptr));
        Pokupbutton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\214", nullptr));
        label_3->setText(QApplication::translate("MainWindow", " FNS - electronic store!", nullptr));
        label_4->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\266\320\260\320\273\321\203\320\271\321\201\321\202\320\260, \320\262\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\272\320\265\320\274 \320\262\321\213 \321\217\320\262\320\273\321\217\320\265\321\202\320\265\321\201\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
