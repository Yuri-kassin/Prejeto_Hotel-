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

void gravar(){
    Coisa aux("","","","","");
    Coisa aux2("","","","","");
    lde = new LDE<Coisa>;
    lde = arv->erdd();
    ofstream arq;
    arq.open("aquivo.txt");
    for(int i = 0; i<lde->getN(); i++){
         try{
            aux=lde->interador(i);
            if((i-1) != -1) aux2=lde->interador(i-1);
        }
        catch(const std::exception& ex){
            cout<<"bugado "<<aux.getPrimNome()<<endl;
        }

        cout<<aux.getPrimNome()<<" "<<aux.getUltnome()<<" "<<aux.getIdade()<<" "<<aux.getRG()<<" "<<aux.getDias()<<endl;
       if(aux!=aux2) arq<<aux.getPrimNome()<<" "<<aux.getUltnome()<<" "<<aux.getIdade()<<" "<<aux.getRG()<<" "<<aux.getDias()<<" "<<aux.getCheck()<<" "<<aux.getQuarto()<<endl;
        cout<<"foi"<<endl;
    }


    arq.close();
}

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

void MainWindow::on_CheckinButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_8_clicked()
{
    QString nome = ui->textEdit->toPlainText();
    string Snome = nome.toStdString();
    ui->textEdit->setText("");
    string quarto;
    if(ui->radioButton->isChecked()) quarto = "01";
    else if(ui->radioButton_2->isChecked()) quarto = "02";
    else if(ui->radioButton_3->isChecked()) quarto = "03";
    else if(ui->radioButton_4->isChecked()) quarto = "04";
    else if(ui->radioButton_5->isChecked()) quarto = "05";
    else if(ui->radioButton_6->isChecked()) quarto = "06";
    Coisa x = (arv->busca(Snome))->getonlyValor();
    arv->remove(x);
    x.setCheck("1");
    x.setQuarto(quarto);
    arv->insere(x);
    gravar();
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_BuscaButton_clicked()
{
    QString a = ui->textEdit_2->toPlainText();
    string aa = a.toStdString();
    Coisa x = (arv->busca(aa))->getonlyValor();
    string nome = x.getPrimNome();
    QString nome1 = QString::fromStdString(x.getPrimNome());
    QString nome2 = QString::fromStdString(x.getUltnome());
    QString idade = QString::fromStdString(x.getIdade());
    QString RG = QString::fromStdString(x.getRG());
    QString dias = QString::fromStdString(x.getDias());
    QString check = QString::fromStdString(x.getCheck());
    QString quarto = QString::fromStdString(x.getQuarto());
     ui->textBrowser->setText("Resultado:\n nome: "+nome1+" sobrenome: "+nome2+" idade: "+idade+" RG: "+RG+" dias que ira passar: "+dias+" Check: "+check+" Quarto: "+quarto+"\n");
    //ui->textBrowser->setText("nome: "+nome);

}
