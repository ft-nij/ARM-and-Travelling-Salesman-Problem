#include "auto.h"
#include "ui_auto.h"
#include "sotrudnik.h"
#include "QMessageBox"

Auto::Auto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Auto)
{
    ui->setupUi(this);
}

Auto::~Auto()
{
    delete ui;
}

void Auto::set_db(QSqlDatabase db)
{
    this->db = db;
}

void Auto::on_AutoButton_clicked()
{
    QString login1=ui->login->text();
    QString password1=ui->password->text();
    if((login1=="Никита Голубцов"&& password1=="123")||(login1=="Фёдор Цыбуцынин"&& password1=="456")||(login1=="Савелий Корючкин"&& password1=="789"))
    {
    Sotrudnik *WindSotrud = new Sotrudnik;
    WindSotrud->setWindowModality(Qt::ApplicationModal);
    WindSotrud->set_db(db);
    close();
    WindSotrud->show();
    }
    else
    {
        QMessageBox::warning(this,"Авторизация","Неверный логин или пароль!\n""Проверьте правильность ввода данных!");
    }
}

