#ifndef HOSPEDES_H
#define HOSPEDES_H

#include <QDialog>

namespace Ui {
class Hospedes;
}

class Hospedes : public QDialog
{
    Q_OBJECT

public:
    explicit Hospedes(QWidget *parent = 0);
    ~Hospedes();

private slots:
    void on_btNovoHospede_clicked();

private:
    Ui::Hospedes *ui;
};

#endif // HOSPEDES_H
