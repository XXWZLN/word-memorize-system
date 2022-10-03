/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QPushButton *signIn;
    QLabel *account_l;
    QLabel *password_l;
    QPushButton *signUp;
    QLineEdit *account;
    QLineEdit *password;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(800, 600);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        signIn = new QPushButton(centralwidget);
        signIn->setObjectName(QStringLiteral("signIn"));
        signIn->setGeometry(QRect(330, 360, 112, 34));
        account_l = new QLabel(centralwidget);
        account_l->setObjectName(QStringLiteral("account_l"));
        account_l->setGeometry(QRect(130, 160, 81, 18));
        password_l = new QLabel(centralwidget);
        password_l->setObjectName(QStringLiteral("password_l"));
        password_l->setGeometry(QRect(130, 240, 81, 18));
        signUp = new QPushButton(centralwidget);
        signUp->setObjectName(QStringLiteral("signUp"));
        signUp->setGeometry(QRect(330, 420, 112, 34));
        account = new QLineEdit(centralwidget);
        account->setObjectName(QStringLiteral("account"));
        account->setGeometry(QRect(300, 150, 271, 31));
        password = new QLineEdit(centralwidget);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(300, 240, 271, 31));
        login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(login);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 30));
        login->setMenuBar(menubar);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QApplication::translate("login", "login", Q_NULLPTR));
        signIn->setText(QApplication::translate("login", "Sign In", Q_NULLPTR));
        account_l->setText(QApplication::translate("login", "\350\264\246\345\217\267", Q_NULLPTR));
        password_l->setText(QApplication::translate("login", "\345\257\206\347\240\201", Q_NULLPTR));
        signUp->setText(QApplication::translate("login", "Sign Up", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
