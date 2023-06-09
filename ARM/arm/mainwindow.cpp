#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bd.h"
#include "register.h"
#include"auto.h"
#include"QMessageBox"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/imgonline-com-ua-Resize-joefOmnvrd.jpg");
    QPixmap pix1(":/resources/img/мал лого.jpg");
    db = QSqlDatabase::addDatabase(("QSQLITE"));
    db.setDatabaseName("./DB");
    if (db.open())
    {
        qDebug("open!");
    }
    else
    {
        qDebug("no open!");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_SotButton_clicked()
{
    Auto *WindAuto = new Auto;
    WindAuto->setWindowModality(Qt::ApplicationModal);
    WindAuto->set_db(db);
    WindAuto->show();
}


void MainWindow::on_Pokupbutton_clicked()
{
    Register *WindRegister = new Register;
    WindRegister->setWindowModality(Qt::ApplicationModal);
    WindRegister->set_db(db);
    WindRegister->show();
}

