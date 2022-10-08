/********************************************************************************
** Form generated from reading UI file 'wordslibrary.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORDSLIBRARY_H
#define UI_WORDSLIBRARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wordslibrary
{
public:
    QPushButton *signOut;
    QTableView *tableView;
    QPushButton *add;
    QPushButton *Delete;

    void setupUi(QWidget *wordslibrary)
    {
        if (wordslibrary->objectName().isEmpty())
            wordslibrary->setObjectName(QStringLiteral("wordslibrary"));
        wordslibrary->resize(688, 480);
        signOut = new QPushButton(wordslibrary);
        signOut->setObjectName(QStringLiteral("signOut"));
        signOut->setGeometry(QRect(560, 40, 112, 34));
        tableView = new QTableView(wordslibrary);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(40, 40, 441, 331));
        add = new QPushButton(wordslibrary);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(560, 100, 112, 34));
        Delete = new QPushButton(wordslibrary);
        Delete->setObjectName(QStringLiteral("Delete"));
        Delete->setGeometry(QRect(560, 160, 112, 34));

        retranslateUi(wordslibrary);

        QMetaObject::connectSlotsByName(wordslibrary);
    } // setupUi

    void retranslateUi(QWidget *wordslibrary)
    {
        wordslibrary->setWindowTitle(QApplication::translate("wordslibrary", "Form", Q_NULLPTR));
        signOut->setText(QApplication::translate("wordslibrary", "Sign Out", Q_NULLPTR));
        add->setText(QApplication::translate("wordslibrary", "Add word", Q_NULLPTR));
        Delete->setText(QApplication::translate("wordslibrary", "Delete", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class wordslibrary: public Ui_wordslibrary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDSLIBRARY_H
