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
    sign_in_account = account;
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

void wordslibrary::on_add_clicked()
{
    QString insert = QString("insert into '%1' values (null,null)").arg(sign_in_account);
    sql_query.exec(insert);
    model->select();
}

void wordslibrary::on_Delete_clicked()
{
    auto index = ui->tableView->currentIndex();
//    int row = index.row();
//    int column = index.column();
    QVariant data = index.data();
    QString select = QString("delete from %1 where word = '%2'").arg(sign_in_account).arg(data.toString());
    qDebug() << select;
    sql_query.exec(select);
    model->select();
}
