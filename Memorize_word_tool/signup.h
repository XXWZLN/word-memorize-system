#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "login.h"

namespace Ui {
class signUp;
}

class signUp : public QWidget
{
    Q_OBJECT

public:
    explicit signUp(QWidget *parent = nullptr);
    ~signUp();

private slots:
    void on_pushButton_clicked();

private:
    Ui::signUp *ui;
    QSqlDatabase database;
    QSqlQuery sql_query;
};

#endif // SIGNUP_H
