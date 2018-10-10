#ifndef ADDHOSPEDE_H
#define ADDHOSPEDE_H

#include <QDialog>

namespace Ui {
class AddHospede;
}

class AddHospede : public QDialog
{
    Q_OBJECT

public:
    explicit AddHospede(QWidget *parent = 0);
    ~AddHospede();

private:
    Ui::AddHospede *ui;
};

#endif // ADDHOSPEDE_H
