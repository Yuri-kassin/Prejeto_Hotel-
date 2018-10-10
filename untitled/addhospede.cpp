#include "addhospede.h"
#include "ui_addhospede.h"

AddHospede::AddHospede(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddHospede)
{
    ui->setupUi(this);
}

AddHospede::~AddHospede()
{
    delete ui;
}
