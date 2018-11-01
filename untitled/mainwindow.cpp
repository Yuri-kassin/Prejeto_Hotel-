#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"hospedes.h"
#include<iostream>
#include<fstream>
#include "Arvore.hpp"
#include "LDE.hpp"
#include "Queue.hpp"
#include"Coisa.hpp"
#include <exception>

using namespace std;

Arvore<Coisa> *arv;
LDE<Coisa> *lde;
Queue<Coisa> fila;

void ler(){
    string nom1,nom2,idade,rg,dias,check,quarto;
    ifstream arq;
    arv = new Arvore<Coisa>;
    arq.open("aquivo.txt");
    if(arq.is_open()){

        while(!arq.eof()){
            arq>>nom1>>nom2>>idade>>rg>>dias>>check>>quarto;
            Coisa a(nom1,nom2,idade,rg,dias);
            a.setCheck(check);
            a.setQuarto(quarto);
            arv->insere(a);
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
    Coisa aux("","","","","");
    Coisa aux2("","","","","");
    ui->textBrowser->setText("");
    ler();
//    string g = "manteiga";
//    QString l = QString::fromStdString(g);
//    ui->textBrowser->setText(l+"\npao");
    lde = arv->erdd();
    cout<<"hmm"<<endl;
//    try{
//      Coisa aux=lde->interador(0);
//   }
//   catch(const std::exception& ex){
//   }
    cout<<"n "<<lde->getN()<<endl;
    for(int i = 0; i<lde->getN(); i++){
         try{
            aux=lde->interador(i);
            if((i-1) != -1) aux2=lde->interador(i-1);
        }
        catch(const std::exception& ex){
            cout<<"bugado "<<aux.getPrimNome()<<endl;
        }
        cout<<"aqui?"<<endl;
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
        cout<<"opa meu consagrado"<<endl;
        cout<<aux.getPrimNome()<<" "<<aux.getUltnome()<<" "<<aux.getIdade()<<" "<<aux.getRG()<<" "<<aux.getDias()<<endl;
       if(aux!=aux2) ui->textBrowser->append("nome: "+nome1+" sobrenome: "+nome2+" idade: "+idade+" RG: "+RG+" dias que ira passar: "+dias+" Check: "+check+" Quarto: "+quarto+"\n");
        cout<<"foi"<<endl;
    }

     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_CheckButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_VoltarButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
