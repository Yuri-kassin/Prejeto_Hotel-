/********************************************************************************
** Form generated from reading UI file 'addhospede.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDHOSPEDE_H
#define UI_ADDHOSPEDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AddHospede
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;
    QLabel *label_2;
    QPushButton *BtCadastrar;
    QPushButton *Btvoltar;

    void setupUi(QDialog *AddHospede)
    {
        if (AddHospede->objectName().isEmpty())
            AddHospede->setObjectName(QString::fromUtf8("AddHospede"));
        AddHospede->resize(792, 545);
        label = new QLabel(AddHospede);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 801, 551));
        label->setPixmap(QPixmap(QString::fromUtf8(":/imagens/fundo-vermelho.jpg")));
        textBrowser = new QTextBrowser(AddHospede);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(100, 50, 256, 31));
        label_2 = new QLabel(AddHospede);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(43, 50, 51, 31));
        BtCadastrar = new QPushButton(AddHospede);
        BtCadastrar->setObjectName(QString::fromUtf8("BtCadastrar"));
        BtCadastrar->setGeometry(QRect(170, 150, 80, 25));
        Btvoltar = new QPushButton(AddHospede);
        Btvoltar->setObjectName(QString::fromUtf8("Btvoltar"));
        Btvoltar->setGeometry(QRect(670, 500, 80, 25));

        retranslateUi(AddHospede);

        QMetaObject::connectSlotsByName(AddHospede);
    } // setupUi

    void retranslateUi(QDialog *AddHospede)
    {
        AddHospede->setWindowTitle(QApplication::translate("AddHospede", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("AddHospede", "Nome", nullptr));
        BtCadastrar->setText(QApplication::translate("AddHospede", "Cadastrar", nullptr));
        Btvoltar->setText(QApplication::translate("AddHospede", "Votlar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddHospede: public Ui_AddHospede {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDHOSPEDE_H
