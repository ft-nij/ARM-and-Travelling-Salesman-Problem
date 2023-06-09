#ifndef SOTRUDNIK_H
#define SOTRUDNIK_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class Sotrudnik;
}

class Sotrudnik : public QWidget
{
    Q_OBJECT

public:
    explicit Sotrudnik(QWidget *parent = nullptr);
    ~Sotrudnik();
    void set_db(QSqlDatabase db);

private slots:
    void on_BDButton_clicked();

    void on_btnOrders_clicked();

    void on_pushButton_clicked();

private:
    Ui::Sotrudnik *ui;
    QSqlDatabase db;

};

#endif // SOTRUDNIK_H
