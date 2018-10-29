#include "hospedes.h"
#include "ui_hospedes.h"
#include "addhospede.h"
#include<iostream>
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
   QString nome = ui->textNome->toPlainText();
   QString idade = ui->textIdade->toPlainText();
   QString RG = ui->textRPG->toPlainText();

   ui->lbteste->setText(nome);

    //close();
}
