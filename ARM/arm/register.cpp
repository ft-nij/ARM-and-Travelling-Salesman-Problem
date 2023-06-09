#include "register.h"
#include "ui_register.h"
#include <QMessageBox>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::set_db(QSqlDatabase db)
{
    this->db = db;
}

void Register::on_btnRegister_clicked()
{
    QSqlQuery query1 = QSqlQuery(db);
    QString Surname = ui->inputSurname->text();
    QString Name = ui->inputName->text();
    QString Patronymic = ui->inputPatronymic->text();
        QSqlQuery query = QSqlQuery(db);
        bool found = 0;
        QString res = Surname + " " + Name;
        QString check = QString("SELECT Client, Product, Status FROM Orders WHERE Client = '%1'").arg(res);
        if (query.exec(check) && query.next()) found = 1;
        if (found){
            Info* Window = new Info(query.value(2).toString());
            Window->show();
            Window->setWindowModality(Qt::ApplicationModal);
            hide();
        }
        else {
            QMessageBox::warning(this,"Статус заказа:\n", "Ваш заказ не найден!");
        }
}


void Register::on_pushButton_clicked()
{
    QSqlQuery query1 = QSqlQuery(db);
    QString Surname = ui->inputSurname->text();
    QString Name = ui->inputName->text();
    QString Patronymic = ui->inputPatronymic->text();
    int Phone = ui->inputPhone->text().toInt();
    QString check = QString("SELECT Surname, Name, MiddleName, Number FROM Database "
                              "WHERE Surname = '%1' AND "
                              "Name = '%2' AND "
                              "MiddleName = '%3' AND "
                              "Number = '%4'" ).arg(Surname, Name, Patronymic, QString::number(Phone));
        QSqlQuery query = QSqlQuery(db);
        query.exec("INSERT INTO Database (Surname, Name, MiddleName, Number) "
                       "VALUES (?, ?, ?, ?)");
        query.addBindValue(Surname);
        query.addBindValue(Name);
        query.addBindValue(Patronymic);
        query.addBindValue(Phone);
        query.exec();
        Catalog *Window = new Catalog;
        Window->set_db(db);
        Window->setWindowModality(Qt::ApplicationModal);
        QString res = Surname + " " + Name;
        Window->setName(res);
        Window->show();
        hide();
}

