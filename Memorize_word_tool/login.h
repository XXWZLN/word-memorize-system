#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "wordslibrary.h"
#include "signup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_signIn_clicked();

    void on_signUp_clicked();

    bool sign_in_check(QString account_input, QString password_input);

private:
    Ui::login *ui;
    QSqlDatabase database;
    QSqlQuery sql_query;
};
#endif // LOGIN_H
