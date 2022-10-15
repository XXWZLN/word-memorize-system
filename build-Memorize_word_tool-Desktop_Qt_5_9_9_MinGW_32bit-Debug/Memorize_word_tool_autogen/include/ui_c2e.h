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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;

    void setupUi(QWidget *c2e)
    {
        if (c2e->objectName().isEmpty())
            c2e->setObjectName(QStringLiteral("c2e"));
        c2e->resize(400, 440);
        pushButton = new QPushButton(c2e);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 30, 112, 34));
        pushButton_2 = new QPushButton(c2e);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 160, 112, 34));
        pushButton_3 = new QPushButton(c2e);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 220, 112, 34));
        pushButton_4 = new QPushButton(c2e);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(120, 290, 112, 34));
        label = new QLabel(c2e);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 100, 81, 18));

        retranslateUi(c2e);

        QMetaObject::connectSlotsByName(c2e);
    } // setupUi

    void retranslateUi(QWidget *c2e)
    {
        c2e->setWindowTitle(QApplication::translate("c2e", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("c2e", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("c2e", "PushButton", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("c2e", "PushButton", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("c2e", "PushButton", Q_NULLPTR));
        label->setText(QApplication::translate("c2e", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class c2e: public Ui_c2e {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C2E_H
