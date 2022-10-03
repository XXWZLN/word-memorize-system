#include "wordslibrary.h"
#include "ui_wordslibrary.h"
#include "login.h"

wordslibrary::wordslibrary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wordslibrary)
{
    ui->setupUi(this);
}

wordslibrary::~wordslibrary()
{
    delete ui;
}

void wordslibrary::sqlInit(QString account)
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(QApplication::applicationDirPath() + "/data.db");
    if(!database.open())
    {
        qDebug()<<"error";
    }
    sql_query = QSqlQuery(database);
    model = new QSqlTableModel(this, database);
    model->setTable(account);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    ui->tableView->setModel(model);
    model->select();
}

void wordslibrary::on_signOut_clicked()
{
    this->close();
    login *Login = new login;
    Login->show();
}
