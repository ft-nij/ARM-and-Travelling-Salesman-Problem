#include "sotrudnik.h"
#include "ui_sotrudnik.h"
#include "bd.h"
#include "catalog.h"

Sotrudnik::Sotrudnik(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sotrudnik)
{
    ui->setupUi(this);
}

Sotrudnik::~Sotrudnik()
{
    delete ui;
}

void Sotrudnik::set_db(QSqlDatabase db)
{
    this->db = db;
}

void Sotrudnik::on_BDButton_clicked()
{
    BD *Window = new BD("Database");
    Window->set_db(db);
    Window->setWindowModality(Qt::ApplicationModal);
    Window->show();
}


void Sotrudnik::on_btnOrders_clicked()
{
    BD *Window = new BD("Orders");
    Window->set_db(db);
    Window->setWindowModality(Qt::ApplicationModal);
    Window->show();
}


void Sotrudnik::on_pushButton_clicked()
{
    BD *Window = new BD("Products");
    Window->set_db(db);
    Window->setWindowModality(Qt::ApplicationModal);
    Window->show();
}

