#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"hospedes.h"
#include<iostream>

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
//    cout<<"a"<<endl;
}

void MainWindow::on_ListButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_CheckButton_clicked()
{

}

void MainWindow::on_VoltarButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
