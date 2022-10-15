/********************************************************************************
** Form generated from reading UI file 'e2c.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_E2C_H
#define UI_E2C_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_e2c
{
public:
    QLabel *label;
    QPushButton *back;
    QPushButton *c1;
    QPushButton *c2;
    QPushButton *c3;

    void setupUi(QWidget *e2c)
    {
        if (e2c->objectName().isEmpty())
            e2c->setObjectName(QStringLiteral("e2c"));
        e2c->resize(400, 440);
        label = new QLabel(e2c);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 120, 81, 18));
        back = new QPushButton(e2c);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(20, 40, 112, 34));
        c1 = new QPushButton(e2c);
        c1->setObjectName(QStringLiteral("c1"));
        c1->setGeometry(QRect(130, 190, 112, 34));
        c2 = new QPushButton(e2c);
        c2->setObjectName(QStringLiteral("c2"));
        c2->setGeometry(QRect(120, 250, 112, 34));
        c3 = new QPushButton(e2c);
        c3->setObjectName(QStringLiteral("c3"));
        c3->setGeometry(QRect(120, 310, 112, 34));

        retranslateUi(e2c);

        QMetaObject::connectSlotsByName(e2c);
    } // setupUi

    void retranslateUi(QWidget *e2c)
    {
        e2c->setWindowTitle(QApplication::translate("e2c", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("e2c", "TextLabel", Q_NULLPTR));
        back->setText(QApplication::translate("e2c", "back", Q_NULLPTR));
        c1->setText(QApplication::translate("e2c", "PushButton", Q_NULLPTR));
        c2->setText(QApplication::translate("e2c", "PushButton", Q_NULLPTR));
        c3->setText(QApplication::translate("e2c", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class e2c: public Ui_e2c {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_E2C_H
