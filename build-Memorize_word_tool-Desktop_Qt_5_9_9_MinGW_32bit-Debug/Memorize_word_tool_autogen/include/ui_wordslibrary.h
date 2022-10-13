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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
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
    QPushButton *memory;
    QLineEdit *search_word;
    QPushButton *Import;
    QComboBox *comboBox;

    void setupUi(QWidget *wordslibrary)
    {
        if (wordslibrary->objectName().isEmpty())
            wordslibrary->setObjectName(QStringLiteral("wordslibrary"));
        wordslibrary->resize(856, 544);
        signOut = new QPushButton(wordslibrary);
        signOut->setObjectName(QStringLiteral("signOut"));
        signOut->setGeometry(QRect(660, 60, 112, 34));
        tableView = new QTableView(wordslibrary);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(40, 110, 581, 331));
        add = new QPushButton(wordslibrary);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(660, 120, 112, 34));
        Delete = new QPushButton(wordslibrary);
        Delete->setObjectName(QStringLiteral("Delete"));
        Delete->setGeometry(QRect(660, 180, 112, 34));
        memory = new QPushButton(wordslibrary);
        memory->setObjectName(QStringLiteral("memory"));
        memory->setGeometry(QRect(650, 250, 112, 34));
        search_word = new QLineEdit(wordslibrary);
        search_word->setObjectName(QStringLiteral("search_word"));
        search_word->setGeometry(QRect(630, 330, 181, 25));
        Import = new QPushButton(wordslibrary);
        Import->setObjectName(QStringLiteral("Import"));
        Import->setGeometry(QRect(660, 380, 112, 34));
        comboBox = new QComboBox(wordslibrary);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(70, 70, 121, 24));

        retranslateUi(wordslibrary);

        QMetaObject::connectSlotsByName(wordslibrary);
    } // setupUi

    void retranslateUi(QWidget *wordslibrary)
    {
        wordslibrary->setWindowTitle(QApplication::translate("wordslibrary", "Form", Q_NULLPTR));
        signOut->setText(QApplication::translate("wordslibrary", "Sign Out", Q_NULLPTR));
        add->setText(QApplication::translate("wordslibrary", "Add word", Q_NULLPTR));
        Delete->setText(QApplication::translate("wordslibrary", "Delete", Q_NULLPTR));
        memory->setText(QApplication::translate("wordslibrary", "Memorize", Q_NULLPTR));
        Import->setText(QApplication::translate("wordslibrary", "Import", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("wordslibrary", "\345\215\225\350\257\215\351\241\272\345\272\217", Q_NULLPTR)
         << QApplication::translate("wordslibrary", "\345\215\225\350\257\215\351\200\206\345\272\217", Q_NULLPTR)
         << QApplication::translate("wordslibrary", "\350\256\260\345\277\206\345\272\246\351\241\272\345\272\217", Q_NULLPTR)
         << QApplication::translate("wordslibrary", "\350\256\260\345\277\206\345\272\246\351\200\206\345\272\217", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class wordslibrary: public Ui_wordslibrary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDSLIBRARY_H
