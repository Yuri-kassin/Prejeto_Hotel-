#include "hospedes.h"
#include "ui_hospedes.h"
#include "addhospede.h"
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

void Hospedes::on_btNovoHospede_clicked()
{
    close();
//    AddHospede *A = new AddHospede;
//    A->setModal(true);
//    A->show();
//    A->exec();


}
