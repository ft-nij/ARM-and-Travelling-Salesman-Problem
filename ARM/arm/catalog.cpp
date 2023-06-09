#include "catalog.h"
#include "ui_catalog.h"

#include <QDebug>
#include "mainwindow.h"

Catalog::Catalog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Catalog)
{
    ui->setupUi(this);
    vec.clear();
    ui->comboType->addItem("Часы");
    ui->comboType->addItem("Телефон");
    ui->comboType->addItem("Наушники");
    ui->comboType->addItem("Ноутбук");

}

Catalog::~Catalog()
{
    delete ui;
}

void Catalog::setName(QString Name)
{
    this->Name = Name;
}

void Catalog::set_db(QSqlDatabase db)
{
    this->db = db;
}

void Catalog::on_btnProduct_clicked()
{
    QSqlQuery query = QSqlQuery(db);
    query.exec("INSERT INTO Orders (Client, Product, Status) "
                   "VALUES (?, ?, ?)");
    query.addBindValue(Name);
    query.addBindValue(Product);
    query.addBindValue("Обрабатывается");
    query.exec();
    hide();
}


void Catalog::on_comboType_currentIndexChanged(const QString &arg1)
{
    vec.clear();
    ui->comboProduct->clear();
    QSqlQuery query = QSqlQuery(db);
    if (arg1 == "Телефон"){
        query.exec("SELECT Products.Name, Products.Price, Products.Amount FROM Products WHERE Products.Type = 'Телефон'");
    }
    if (arg1 == "Ноутбук"){
        query.exec("SELECT Products.Name, Products.Price, Products.Amount FROM Products WHERE Products.Type = 'Ноутбук'");
    }
    if (arg1 == "Часы"){
        query.exec("SELECT Products.Name, Products.Price, Products.Amount FROM Products WHERE Products.Type = 'Часы'");
    }
    if (arg1 == "Наушники"){
        query.exec("SELECT Products.Name, Products.Price, Products.Amount FROM Products WHERE Products.Type = 'Наушники'");
    }
    query.next();
    QString res = query.value(0).toString() + " " + query.value(1).toString() + " р. (" + query.value(2).toString() + " шт)" ;
    ui->comboProduct->addItem(res);
    Product = query.value(0).toString();
    vec.push_back(query.value(0).toString());
    while (query.next()){
        QString res = query.value(0).toString() + " " + query.value(1).toString() + " р. (" + query.value(2).toString() + " шт)" ;
        ui->comboProduct->addItem(res);
        vec.push_back(query.value(0).toString());

    }

}


void Catalog::on_comboProduct_currentIndexChanged(const QString &arg1)
{
      for (auto it = vec.begin(); it != vec.end(); ++it){
          if (arg1.indexOf(*it) != -1){
              this->Product = *it;
          }
      }
}


void Catalog::on_comboProduct_textActivated(const QString &arg1)
{
    vec.clear();
    ui->comboProduct->clear();
    QSqlQuery query = QSqlQuery(db);
    QString search = QString("SELECT Name FROM Products WHERE Name = '%1'").arg(arg1);
    query.exec("SELECT Name FROM Products WHERE Name = search");
    query.next();
}

