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
    QString insert = QString("insert into '%1' values (null,null,1)").arg(sign_in_account);
    sql_query.exec(insert);
    model->select();
}

void wordslibrary::on_Delete_clicked()
{
    auto index = ui->tableView->currentIndex();
    QVariant data = index.data();
    QString select = QString("delete from %1 where word = '%2'").arg(sign_in_account).arg(data.toString());
    sql_query.exec(select);
    model->select();
}

void wordslibrary::on_search_word_textChanged(const QString &arg1)
{
    QString text = ui->search_word->text();
    QString data = QString("");
    for(int i = 0; i < ui->tableView->model()->rowCount(); i++)
    {
        ui->tableView->setRowHidden(i,true);
        for(int j = 0; j < ui->tableView->model()->columnCount() - 1; j++)
        {
            data = QString("");
            auto index = ui->tableView->model()->index(i,j);
            data = ui->tableView->model()->data(index).toString();
            qDebug() << data;
            if(data.contains(text, Qt::CaseSensitive))
                ui->tableView->setRowHidden(i,false);
        }
    }
}


void wordslibrary::on_comboBox_currentIndexChanged(const QString &arg1)
{
    auto index = ui->comboBox->currentIndex();
    switch (index) {
        case 0:
            ui->tableView->sortByColumn(0,Qt::AscendingOrder);
            break;
        case 1:
            ui->tableView->sortByColumn(0,Qt::DescendingOrder);
            break;
        case 2:
            ui->tableView->sortByColumn(2,Qt::AscendingOrder);
            break;
        case 3:
            ui->tableView->sortByColumn(2,Qt::DescendingOrder);
            break;
    }
}

