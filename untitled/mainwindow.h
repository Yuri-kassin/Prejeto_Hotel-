#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_botao1_clicked();

    void on_pushButton_clicked();

    void on_label_2_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
