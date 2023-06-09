#include "info.h"
#include "ui_info.h"

Info::Info(QString status, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);
    ui->showInfo->setText(status);
}

Info::~Info()
{
    delete ui;
}

