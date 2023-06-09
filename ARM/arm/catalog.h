#ifndef CATALOG_H
#define CATALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class Catalog;
}

class Catalog : public QDialog
{
    Q_OBJECT

public:
    explicit Catalog(QWidget *parent = nullptr);
    ~Catalog();
    void setName(QString Name);
    void set_db(QSqlDatabase db);

private slots:
    void on_btnProduct_clicked();

    //void on_comboProduct_currentIndexChanged(const QString &arg1);

    void on_comboType_currentIndexChanged(const QString &arg1);

    void on_comboProduct_currentIndexChanged(const QString &arg1);

    void on_comboProduct_textActivated(const QString &arg1);

private:
    Ui::Catalog *ui;
    QSqlDatabase db;
    QString Name;
    QString Product;
    QVector<QString> vec;
};

#endif // CATALOG_H
