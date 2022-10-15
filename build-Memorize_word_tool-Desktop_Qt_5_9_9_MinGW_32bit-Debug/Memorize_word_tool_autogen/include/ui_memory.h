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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_memory
{
public:
    QPushButton *back;
    QPushButton *c2e;
    QPushButton *pushButton_5;
    QSpinBox *me_num;

    void setupUi(QWidget *memory)
    {
        if (memory->objectName().isEmpty())
            memory->setObjectName(QStringLiteral("memory"));
        memory->resize(287, 353);
        back = new QPushButton(memory);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(70, 260, 112, 34));
        c2e = new QPushButton(memory);
        c2e->setObjectName(QStringLiteral("c2e"));
        c2e->setGeometry(QRect(70, 40, 112, 34));
        pushButton_5 = new QPushButton(memory);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 110, 112, 34));
        me_num = new QSpinBox(memory);
        me_num->setObjectName(QStringLiteral("me_num"));
        me_num->setGeometry(QRect(90, 190, 91, 25));

        retranslateUi(memory);

        QMetaObject::connectSlotsByName(memory);
    } // setupUi

    void retranslateUi(QWidget *memory)
    {
        memory->setWindowTitle(QApplication::translate("memory", "Form", Q_NULLPTR));
        back->setText(QApplication::translate("memory", "Back", Q_NULLPTR));
        c2e->setText(QApplication::translate("memory", "\344\270\255-\350\213\261", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("memory", "\350\213\261-\344\270\255", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        me_num->setToolTip(QApplication::translate("memory", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class memory: public Ui_memory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORY_H
