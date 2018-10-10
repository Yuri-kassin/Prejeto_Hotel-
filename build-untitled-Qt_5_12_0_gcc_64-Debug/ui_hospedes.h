/********************************************************************************
** Form generated from reading UI file 'hospedes.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOSPEDES_H
#define UI_HOSPEDES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Hospedes
{
public:
    QLabel *label;
    QPushButton *btNovoHospede;
    QLabel *lbPessoa0;

    void setupUi(QDialog *Hospedes)
    {
        if (Hospedes->objectName().isEmpty())
            Hospedes->setObjectName(QString::fromUtf8("Hospedes"));
        Hospedes->resize(792, 545);
        label = new QLabel(Hospedes);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 791, 551));
        label->setPixmap(QPixmap(QString::fromUtf8(":/imagens/fundo-vermelho.jpg")));
        btNovoHospede = new QPushButton(Hospedes);
        btNovoHospede->setObjectName(QString::fromUtf8("btNovoHospede"));
        btNovoHospede->setGeometry(QRect(330, 500, 161, 25));
        lbPessoa0 = new QLabel(Hospedes);
        lbPessoa0->setObjectName(QString::fromUtf8("lbPessoa0"));
        lbPessoa0->setGeometry(QRect(20, 30, 111, 41));

        retranslateUi(Hospedes);

        QMetaObject::connectSlotsByName(Hospedes);
    } // setupUi

    void retranslateUi(QDialog *Hospedes)
    {
        Hospedes->setWindowTitle(QApplication::translate("Hospedes", "Dialog", nullptr));
        label->setText(QString());
        btNovoHospede->setText(QApplication::translate("Hospedes", "Cadastrar Novo Hospede", nullptr));
        lbPessoa0->setText(QApplication::translate("Hospedes", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hospedes: public Ui_Hospedes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOSPEDES_H
