#include "e2c.h"
#include "ui_e2c.h"

e2c::e2c(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::e2c)
{
    ui->setupUi(this);
}

void e2c::e2cInit(QString account, int _words_num)
{
    srand((unsigned)time(NULL));
    words_num = _words_num;
//    remb_level_1 = (int)(words_num * 0.6);
//    remb_level_2 = (int)(words_num * 0.3);
//    remb_level_3 = (int)(words_num * 0.05);
//    remb_level_4 = words_num - remb_level_1 - remb_level_2 - remb_level_3;
    sign_in_account = account;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(QApplication::applicationDirPath() + "/data.db");
    if(!database.open())
    {
        qDebug()<<"error";
    }

    sql_query = QSqlQuery(database);
    if(level_num(1) > (int)(words_num * level1))
        remb_level_1 = (int)(words_num * level1);
    else
        remb_level_1 = level_num(1);
}

int e2c::level_num(int level)
{
    int num = 0;
    QString order = QString("select * from %1 where wordTags = %2").arg(sign_in_account).arg(level);
    sql_query.exec(order);
    while(sql_query.next())
    {
        num++;
    }
    return num;
}

int e2c::level_select()
{
    if(words_num > 0)
    {
        int remb_level = rand() % 4 + 1;
        switch (remb_level) {
        case 1:
            if(remb_level_1 > 0){
                remb_level_1--;
                break;
            }
            else
                level_select();
        case 2:
            if(remb_level_2 > 0){
                remb_level_2--;
                break;
            }
            else
                level_select();
        case 3:
            if(remb_level_3 > 0){
                remb_level_3--;
                break;
            }
            else
                level_select();
        case 4:
            if(remb_level_4 > 0){
                remb_level_4--;
                break;
            }
            else
                level_select();
        }
        words_num--;
        return remb_level;
    }
    qDebug() << "背完了";
    return 0;
}

int e2c::word_select(int level)
{

}

e2c::~e2c()
{
    delete ui;
}

void e2c::on_back_clicked()
{
    this->close();
    wordslibrary *Wordslibrary = new wordslibrary();
    Wordslibrary->sqlInit(sign_in_account);
    Wordslibrary->show();
}
