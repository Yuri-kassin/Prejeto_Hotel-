#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"hospedes.h"
#include<iostream>
#include<fstream>
#include "Arvore.hpp"
#include "LDE.hpp"
#include "Queue.hpp"
#include"Coisa.hpp"
using namespace std;

Arvore<Coisa> arv;
LDE<Coisa> lde;
Queue<Coisa> fila;

void ler(){
    string nom1,nom2,idade,rg,dias,check,quarto;
    ifstream arq;
    arq.open("aquivo.txt");
    if(arq.is_open()){
        while(!arq.eof()){
            arq>>nom1>>nom2>>idade>>rg>>dias>>check>>quarto;
            Coisa a(nom1,nom2,idade,rg,dias);
            a.setCheck(check);
            a.setQuarto(quarto);
            arv.insere(a);
        }
    }

    arq.close();
}


using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_botao1_clicked()
//{
//    close();
//    Hospedes *H = new Hospedes;
//    H->setModal(true);
//    H->show();
//    H->exec();

//}



void MainWindow::on_CadastroButton_clicked()
{
//    ui->stackedWidget->setCurrentIndex(1);
    Hospedes *H = new Hospedes;
    H->setModal(true);
    H->exec();
    ler();
}

void MainWindow::on_ListButton_clicked()
{
//    string g = "manteiga";
//    QString l = QString::fromStdString(g);
//    ui->textBrowser->setText(l+"\npao");
    lde = arv.erdd();
    for(int i = 0; i<lde.getN(); i++){
        Coisa aux=lde.interador(i);
        QString nome1 = QString::fromStdString(aux.getPrimNome());
        QString nome2 = QString::fromStdString(aux.getUltnome());
        QString idade = QString::fromStdString(aux.getIdade());
        QString RG = QString::fromStdString(aux.getRG());
        QString dias = QString::fromStdString(aux.getDias());
        QString check;
        if(aux.getCheck()=="0") check = "checkin ainda nao realizado";
        else check = "checkin realizado";
        QString quarto;
        if(aux.getQuarto() == "00") quarto = "ainda nao possui";
        else check = QString::fromStdString(aux.getQuarto());

        ui->textBrowser->setText("nome: "+nome1+" sobrenome: "+nome2+" idade: "+idade+" RG: "+RG+" dias que ira passar: "+" Check: "+check+" Quarto: "+quarto+"\n");
    }

     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_CheckButton_clicked()
{

}

void MainWindow::on_VoltarButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
