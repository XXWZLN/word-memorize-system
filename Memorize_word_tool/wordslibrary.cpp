#include "wordslibrary.h"
#include "ui_wordslibrary.h"


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
    model->setTable(sign_in_account);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    mymodel = new MySqlTableModel(this,database);
    mymodel->setTable(sign_in_account);
    mymodel->setEditStrategy(QSqlTableModel::OnFieldChange);
    ui->tableView->setModel(mymodel);
    myselect = QString("select word,meaning,wordTags from %1").arg(sign_in_account);
    mymodel->MySelect(myselect);
}

void wordslibrary::on_signOut_clicked()
{
    this->close();
    login *Login = new login;
    Login->show();
}

void wordslibrary::on_add_clicked()
{
//    QString insert = QString("insert into '%1' values (null,null,0,0,null,null,null,0,0)").arg(sign_in_account);
//    sql_query.exec(insert);
//    mymodel->MySelect(myselect);
    QString add_text = ui->add_input->text();
    QString order = QString("select * from dictionary where word='%2'").arg(add_text);
    sql_query.exec(order);
    sql_query.first();
    auto a0 = sql_query.value(0).toString();
    auto a1 = sql_query.value(1).toString();
    auto a2 = sql_query.value(2).toString();
    auto a3 = sql_query.value(3).toString();
    auto a4 = sql_query.value(4).toString();
    order = QString("insert into '%1' values ('%2','%3','0','0','%6','%7','%8','0','0')").arg(sign_in_account).arg(a0).arg(a1).arg(a2).arg(a3).arg(a4);
    sql_query.exec(order);
    mymodel->MySelect(myselect);
}

void wordslibrary::on_Delete_clicked()
{
    auto index = ui->tableView->currentIndex();
    QVariant data = index.data();
    QString select = QString("delete from %1 where word = '%2'").arg(sign_in_account).arg(data.toString());
    sql_query.exec(select);
    mymodel->MySelect(myselect);
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


void wordslibrary::on_Import_clicked()
{
    QString order = QString("select * from dictionary");
    sql_query.exec(order);
    while (sql_query.next()) {
        QString a1 = sql_query.value(0).toString();
        QString a2 = sql_query.value(1).toString();
        QString a3 = sql_query.value(2).toString();
        QString a4 = sql_query.value(3).toString();
        QString a5 = sql_query.value(4).toString();
        QString import = QString("insert into '%1' values ('%2','%3','0','0','%6','%7','%8','0','0')").arg(sign_in_account).arg(a1).arg(a2).arg(a3).arg(a4).arg(a5);
        QSqlQuery subQuery(database);
        subQuery.exec(import);

    }

    //sql_query.exec(import);
    mymodel->MySelect(myselect);
}



void wordslibrary::on_memory_clicked()
{
    this->close();
    memory *Memory = new memory();
    Memory->memorize_tool_init(sign_in_account);
    Memory->show();
}
