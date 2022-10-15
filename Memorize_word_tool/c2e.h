#ifndef C2E_H
#define C2E_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "memory.h"


namespace Ui {
class c2e;
}

class c2e : public QWidget
{
    Q_OBJECT

public:
    explicit c2e(QWidget *parent = nullptr);
    ~c2e();

private:
    Ui::c2e *ui;
    QString sign_in_account;
    QSqlDatabase database;
    QSqlQuery sql_query;
};

#endif // C2E_H
