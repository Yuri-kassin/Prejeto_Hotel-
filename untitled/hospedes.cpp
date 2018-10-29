#include "hospedes.h"
#include "ui_hospedes.h"
#include "addhospede.h"
#include"arqaddhosp.hpp"
#include<iostream>

using namespace std;

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
   string Snome = nome.toStdString();
   string Sidade = idade.toStdString();
   string SRG = RG.toStdString();
   ArqAddHosp x(Snome,Sidade,SRG);
   ui->lbteste->setText(nome);

    //close();
}
