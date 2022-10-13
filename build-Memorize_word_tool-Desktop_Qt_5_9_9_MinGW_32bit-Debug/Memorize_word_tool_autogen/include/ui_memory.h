/********************************************************************************
** Form generated from reading UI file 'memory.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORY_H
#define UI_MEMORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_memory
{
public:
    QPushButton *back;

    void setupUi(QWidget *memory)
    {
        if (memory->objectName().isEmpty())
            memory->setObjectName(QStringLiteral("memory"));
        memory->resize(802, 604);
        back = new QPushButton(memory);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(340, 490, 112, 34));

        retranslateUi(memory);

        QMetaObject::connectSlotsByName(memory);
    } // setupUi

    void retranslateUi(QWidget *memory)
    {
        memory->setWindowTitle(QApplication::translate("memory", "Form", Q_NULLPTR));
        back->setText(QApplication::translate("memory", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class memory: public Ui_memory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORY_H
