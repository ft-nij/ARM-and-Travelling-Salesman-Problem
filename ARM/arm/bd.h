#ifndef BD_H
#define BD_H

#include <QWidget>
#include<QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlTableModel>

namespace Ui {
class BD;
}

class BD : public QWidget
{
    Q_OBJECT

public:
    explicit BD(QString type = "", QWidget *parent = nullptr);
    ~BD();
    void set_db(QSqlDatabase db);
    void set_type(QString type);

private slots:
    void on_AddButton_clicked();

    void on_DeleteButton_clicked();
     void on_tableView_clicked(const QModelIndex &index);


private:
    Ui::BD *ui;
    QString type;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    int row;
};

#endif // BD_H
