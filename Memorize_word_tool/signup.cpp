#include "signup.h"
#include "ui_signup.h"


signUp::signUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signUp)
{
    ui->setupUi(this);
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(QApplication::applicationDirPath() + "/data.db");
    if(!database.open())
    {
        qDebug()<<"error";
    }
    sql_query = QSqlQuery(database);
}

signUp::~signUp()
{
    delete ui;
}

void signUp::on_pushButton_clicked()
{
    QString password = ui->password->text();
    QString account = ui->account->text();
    QString newAccount = QString("insert into account values ('%1', '%2')").arg(account).arg(password);
    sql_query.exec(newAccount);
    QString initTable = QString("CREATE TABLE [%1] (        \
                                 word    TEXT,              \
                                 meaning TEXT,              \
                                 wordTags INT,              \
                                 tag1    TEXT,              \
                                 tag2    TEXT               \
                                 );"
                               ).arg(account);
    if(sql_query.exec(initTable))
    {
        this->close();
        wordslibrary *Wordslibrary = new wordslibrary();
        Wordslibrary->sqlInit(account);
        Wordslibrary->show();
    }
    else{
        qDebug() << "account init error";
    }

}
