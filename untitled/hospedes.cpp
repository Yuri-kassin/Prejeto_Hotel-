#include "hospedes.h"
#include "ui_hospedes.h"

Hospedes::Hospedes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hospedes)
{
    ui->setupUi(this);
}

Hospedes::~Hospedes()
{
    delete ui;
}
