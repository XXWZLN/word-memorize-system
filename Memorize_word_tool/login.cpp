#include "login.h"
#include "./ui_login.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(QApplication::applicationDirPath() + "/data.db");
    if(!database.open())
    {
        qDebug()<<"error";
    }
    sql_query = QSqlQuery(database);
    //debug
    sql_query.exec("select * from account");
    while(sql_query.next())
    {
        QString account = sql_query.value(0).toString();
        QString password = sql_query.value(1).toString();
        qDebug()<<QString("account:%1    password:%2").arg(account).arg(password);
    }
    //debug
}

login::~login()
{
    delete ui;
}

bool login::sign_in_check(QString account_input, QString password_input)
{
    QString account;
    QString password;
    sql_query.exec("select * from account");
    while(sql_query.next())
    {
        account = sql_query.value(0).toString();
        if(account != account_input)
        {
            continue;
        }
        password = sql_query.value(1).toString();
        if(password == password_input)
        {
            return true;
        }
        qDebug() << QString("password wrong");
        return false;
    }
    qDebug() << QString("no such account");
    return  false;
}

void login::on_signIn_clicked()
{
    QString password_input = ui->password->text();
    QString account_input = ui->account->text();
    if(sign_in_check(account_input, password_input))
    {
        this->close();
        wordslibrary *Wordslibrary = new wordslibrary();
        Wordslibrary->sqlInit(account_input);
        Wordslibrary->show();
    }
}

void login::on_signUp_clicked()
{
    this->close();
    signUp *signup = new signUp;
    signup->show();
}




