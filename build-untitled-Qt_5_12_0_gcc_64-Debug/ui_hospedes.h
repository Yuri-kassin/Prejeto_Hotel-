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
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Hospedes
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QListView *listView;

    void setupUi(QDialog *Hospedes)
    {
        if (Hospedes->objectName().isEmpty())
            Hospedes->setObjectName(QString::fromUtf8("Hospedes"));
        Hospedes->resize(792, 545);
        label = new QLabel(Hospedes);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 791, 551));
        label->setPixmap(QPixmap(QString::fromUtf8(":/imagens/fundo-vermelho.jpg")));
        pushButton = new QPushButton(Hospedes);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 500, 161, 25));
        listView = new QListView(Hospedes);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(170, 90, 256, 231));

        retranslateUi(Hospedes);

        QMetaObject::connectSlotsByName(Hospedes);
    } // setupUi

    void retranslateUi(QDialog *Hospedes)
    {
        Hospedes->setWindowTitle(QApplication::translate("Hospedes", "Dialog", nullptr));
        label->setText(QString());
        pushButton->setText(QApplication::translate("Hospedes", "Cadastrar Novo Hospede", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hospedes: public Ui_Hospedes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOSPEDES_H
