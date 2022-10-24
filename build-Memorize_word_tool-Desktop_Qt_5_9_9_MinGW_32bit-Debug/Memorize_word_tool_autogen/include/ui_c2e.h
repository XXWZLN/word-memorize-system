/********************************************************************************
** Form generated from reading UI file 'c2e.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C2E_H
#define UI_C2E_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_c2e
{
public:
    QPushButton *back;
    QPushButton *c1;
    QPushButton *c2;
    QPushButton *c3;
    QLabel *label;
    QLabel *error;
    QPushButton *c4;

    void setupUi(QWidget *c2e)
    {
        if (c2e->objectName().isEmpty())
            c2e->setObjectName(QStringLiteral("c2e"));
        c2e->resize(400, 440);
        back = new QPushButton(c2e);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(20, 30, 112, 34));
        c1 = new QPushButton(c2e);
        c1->setObjectName(QStringLiteral("c1"));
        c1->setGeometry(QRect(120, 160, 112, 34));
        c2 = new QPushButton(c2e);
        c2->setObjectName(QStringLiteral("c2"));
        c2->setGeometry(QRect(120, 220, 112, 34));
        c3 = new QPushButton(c2e);
        c3->setObjectName(QStringLiteral("c3"));
        c3->setGeometry(QRect(120, 290, 112, 34));
        label = new QLabel(c2e);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 100, 81, 18));
        error = new QLabel(c2e);
        error->setObjectName(QStringLiteral("error"));
        error->setGeometry(QRect(270, 100, 81, 18));
        c4 = new QPushButton(c2e);
        c4->setObjectName(QStringLiteral("c4"));
        c4->setGeometry(QRect(120, 350, 112, 34));

        retranslateUi(c2e);

        QMetaObject::connectSlotsByName(c2e);
    } // setupUi

    void retranslateUi(QWidget *c2e)
    {
        c2e->setWindowTitle(QApplication::translate("c2e", "Form", Q_NULLPTR));
        back->setText(QApplication::translate("c2e", "PushButton", Q_NULLPTR));
        c1->setText(QApplication::translate("c2e", "PushButton", Q_NULLPTR));
        c2->setText(QApplication::translate("c2e", "PushButton", Q_NULLPTR));
        c3->setText(QApplication::translate("c2e", "PushButton", Q_NULLPTR));
        label->setText(QApplication::translate("c2e", "TextLabel", Q_NULLPTR));
        error->setText(QApplication::translate("c2e", "TextLabel", Q_NULLPTR));
        c4->setText(QApplication::translate("c2e", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class c2e: public Ui_c2e {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C2E_H
