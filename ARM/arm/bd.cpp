#include "bd.h"
#include "ui_bd.h"

BD::BD(QString type, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BD)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this, db);
    model->setTable(type);
    model->select();
    ui->tableView->setModel(model);

}

BD::~BD()
{
    delete ui;
}

void BD::on_AddButton_clicked()
{
    model->insertRow(model->rowCount());
}

void BD::on_DeleteButton_clicked()
{
    model->removeRow(row);
}


void BD::on_tableView_clicked(const QModelIndex &index)
{
    row=index.row();
}

void BD::set_db(QSqlDatabase db)
{
    this->db = db;
}

void BD::set_type(QString type)
{
    this->type = type;
}
