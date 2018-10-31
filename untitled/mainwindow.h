#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<iostream>
#include <QMainWindow>
using namespace std;

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:


    void on_CadastroButton_clicked();

    void on_ListButton_clicked();

    void on_CheckButton_clicked();

    void on_VoltarButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
