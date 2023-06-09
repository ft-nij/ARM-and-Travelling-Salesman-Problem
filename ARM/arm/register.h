#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include "bd.h"
#include "catalog.h"
#include "info.h"

#include "QMessageBox"

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    void set_db(QSqlDatabase db);

private slots:
    void on_btnRegister_clicked();

    void on_pushButton_clicked();

private:
    Ui::Register *ui;
    QSqlDatabase db;
};

#endif // REGISTER_H
