#ifndef AUTO_H
#define AUTO_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class Auto;
}

class Auto : public QWidget
{
    Q_OBJECT

public:
    explicit Auto(QWidget *parent = nullptr);
    ~Auto();
    void set_db(QSqlDatabase db);

private slots:
    void on_AutoButton_clicked();

private:
    Ui::Auto *ui;
    QSqlDatabase db;
};

#endif // AUTO_H
