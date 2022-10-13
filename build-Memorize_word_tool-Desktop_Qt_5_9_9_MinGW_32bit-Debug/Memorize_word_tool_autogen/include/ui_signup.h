/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signUp
{
public:
    QPushButton *pushButton;
    QLineEdit *account;
    QLineEdit *password;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *signUp)
    {
        if (signUp->objectName().isEmpty())
            signUp->setObjectName(QStringLiteral("signUp"));
        signUp->resize(400, 300);
        pushButton = new QPushButton(signUp);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 210, 112, 34));
        account = new QLineEdit(signUp);
        account->setObjectName(QStringLiteral("account"));
        account->setGeometry(QRect(160, 60, 113, 25));
        password = new QLineEdit(signUp);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(160, 110, 113, 25));
        label = new QLabel(signUp);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 60, 81, 18));
        label_2 = new QLabel(signUp);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 110, 81, 18));

        retranslateUi(signUp);

        QMetaObject::connectSlotsByName(signUp);
    } // setupUi

    void retranslateUi(QWidget *signUp)
    {
        signUp->setWindowTitle(QApplication::translate("signUp", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("signUp", "Sign Up", Q_NULLPTR));
        label->setText(QApplication::translate("signUp", "account", Q_NULLPTR));
        label_2->setText(QApplication::translate("signUp", "password", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class signUp: public Ui_signUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
