#include "hospedes.h"
#include "ui_hospedes.h"
#include "addhospede.h"
#include"arqaddhosp.hpp"
#include<iostream>
#include<QMessageBox>

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
   QString sobrenome = ui->textSobrenome->toPlainText();

   string Snome = nome.toStdString();
   string Sidade = idade.toStdString();
   string SRG = RG.toStdString();
   string SSobrenome = sobrenome.toStdString();

   int dias = 0;
   if(ui->R3Button->isCheckable()) dias = 3;
   else if(ui->R7Button->isCheckable()) dias = 7;
   else if(ui->R12Button->isCheckable()) dias = 12;
   else if(ui->R15Button->isCheckable()) dias = 15;

  if((dias != 0)){
   ArqAddHosp x(Snome,Sidade,SRG,SSobrenome,dias);
    close();
  }
  else{
      QMessageBox::information(this,"ALERTA","preencha todos os campos");
  }
}
