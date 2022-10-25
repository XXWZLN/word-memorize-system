#include "c2e.h"
#include "ui_c2e.h"

c2e::c2e(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::c2e)
{
    ui->setupUi(this);
}

void c2e::c2eInit(QString account, int _words_num)
{
    srand((unsigned)time(NULL));
    words_num = _words_num;
    remb_level_expect[0] = (int)(words_num * level0);
    remb_level_expect[1] = (int)(words_num * level1);
    remb_level_expect[2] = (int)(words_num * level2);
    remb_level_expect[3] = (int)(words_num * level3);
    remb_level_expect[4] = words_num - remb_level_expect[0] - remb_level_expect[1] - remb_level_expect[2] - remb_level_expect[3];
    remb_level_expect[5] = 0;
    sign_in_account = account;
    ui->error->setText("");
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(QApplication::applicationDirPath() + "/data.db");
    if(!database.open())
    {
        qDebug()<<"error";
    }
    cishu = 0;
    sql_query = QSqlQuery(database);
    int l;
    right_or_not = 1;
    level_num_all();
    level_num_config();
    l = level_select();
    while(!word_select(l))
    {
        l = level_select();
    }
    words_init(word_now);
}

int c2e::level_num(int level)
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

void c2e::level_num_all()
{
    for(int i = 0; i < 6; i++)
    {
        remb_level[i] = level_num(i);
    }
}

void c2e::level_num_config()
{
    int num_lack = 0;
    for(int i = 0; i < 6; i++)
    {
        remb_practice_minus_expect[i] = remb_level[i] - remb_level_expect[i];
        if(remb_practice_minus_expect[i] < 0)
            num_lack += remb_practice_minus_expect[i];
    }
    for(int j = 0; j < 6; j++)
    {
        if(remb_practice_minus_expect[j] > 0)
        {
            if(num_lack + remb_practice_minus_expect[j] >= 0)
            {
                 remb_level[j] = remb_level_expect[j] - num_lack;
                 if(num_lack + remb_practice_minus_expect[j] <= 0 )
                    num_lack += remb_practice_minus_expect[j];
                 else
                     num_lack = 0;
                 if(j == 5)
                     break;
                 for(int k = j + 1; k < 6; k++)
                 {
                     if(remb_practice_minus_expect[k] >= 0)
                         remb_level[k] = remb_level_expect[k];
                 }
                 break;
            }
            if(num_lack + remb_practice_minus_expect[j] <= 0 )
               num_lack += remb_practice_minus_expect[j];
            else
                num_lack = 0;
        }
    }

}

int c2e::level_select()
{
    int level;
    if(words_num > 0)
    {
        while(1){
            level = rand() % 6;
            switch (level) {
            case 0:
                if(remb_level[0] > 0){
                    return level;
                }
                else
                    break;
            case 1:
                if(remb_level[1] > 0){
                    return level;
                }
                else
                    break;
            case 2:
                if(remb_level[2] > 0){
                    return level;
                }
                else
                    break;
            case 3:
                if(remb_level[3] > 0){
                    return level;
                }
                else
                    break;
            case 4:
                if(remb_level[4] > 0){
                    return level;
                }
                else
                    break;
            case 5:
                if(remb_level[5] > 0){
                    return level;
                }
                else
                    break;
            }
        }
    }
    return -1;
}

int c2e::word_select(int level)
{
    if(level == -1)
    {
        finish();
        return 2;
    }
    QString order = QString("select * from %1 where wordTags = %2 and chosen = 0").arg(sign_in_account).arg(level);
    sql_query.exec(order);

    int row = 0;
    while(sql_query.next())
    {
        row++;
        //qDebug()<<sql_query.value(0);

    }
    //qDebug() << "next";
    if(row == 0)
        return 0;
    row = rand() % row;
    sql_query.first();
    for(int j = 0; j < row; j++)
    {
        sql_query.next();
    }
    //qDebug()<<sql_query.value(0).toString();
    //words_init(sql_query.value(0).toString());
    word_now = sql_query.value(0).toString();
    order = QString("update %1 set chosen = 1 where word = '%2'").arg(sign_in_account).arg(sql_query.value(0).toString());
    sql_query.exec(order);
    remb_level[level]--;
    words_num--;
    return 1;
}

void c2e::words_init(QString word)
{
    right_or_not = 1;
    QString subOrder = QString("select * from dictionary where word='%1'").arg(word);
    sql_query.exec(subOrder);
    sql_query.first();
    ui->label->setText(sql_query.value(1).toString());
    QString wa = sql_query.value(0).toString();

    QString w1 = sql_query.value(2).toString();

    QString w2 = sql_query.value(3).toString();

    QString w3 = sql_query.value(4).toString();
    QVector<QString> words;
    words.append(word);
    words.append(w1);
    words.append(w2);
    words.append(w3);
    ans_index = rand() % 4;
    auto tmp = words[0];
    words[0] = words[ans_index];
    words[ans_index] = tmp;
    ui->c1->setText(words[0]);
    ui->c2->setText(words[1]);
    ui->c3->setText(words[2]);
    ui->c4->setText(words[3]);
    cishu++;
    qDebug () << cishu;
}

void c2e::judgement(int n, int ans, int right_or_not)
{
    QString order = QString ("select * from %1 where word='%2'").arg (sign_in_account).arg (word_now);
    QSqlQuery theQueue(database);
    theQueue.exec(order);
    theQueue.first();
    if (n == ans && right_or_not == 1) {
        //"update %1 set rem_num = rem_num + 1 all_num = all_num + 1 where word = '%2'"
        QString order = QString ("update %1 set rem_num=rem_num+1,all_num=all_num+1 where word='%2'").arg(sign_in_account).arg(word_now);
        sql_query.exec(order);
        ui->error->setText("");
        if (theQueue.value(2) < 3) {
            order = QString ("update %1 set wordTags=2 where word='%2'").arg (sign_in_account).arg (word_now);
            theQueue.exec(order);
        }
        int l;
        l = level_select();
        while(!word_select(l))
        {
            l = level_select();
        }
        words_init(word_now);
    }
    else if (n == ans && right_or_not == 0){
        QString order = QString ("update %1 set all_num=all_num+1 where word='%2'").arg(sign_in_account).arg(word_now);
        sql_query.exec(order);
        ui->error->setText("");

        int l;
        l = level_select();
        while(!word_select(l))
        {
            l = level_select();
        }
        words_init(word_now);
        }
    else if (n != ans) {
        ui->error->setText("错了");
        if (theQueue.value(2) < 3) {
            order = QString ("update %1 set wordTags=1 where word='%2'").arg (sign_in_account).arg (word_now);
            theQueue.exec(order);
        }
    }
}

void c2e::finish()
{
    ui->c1->hide();
    ui->c2->hide();
    ui->c3->hide();
    ui->c4->hide();
    QString order = QString("update %1 set chosen=0").arg (sign_in_account);
    sql_query.exec(order);
    order = QString("select * from %1").arg(sign_in_account);
    sql_query.exec(order);
    while (sql_query.next())
    {
        float r = sql_query.value(7).toFloat();
        float a = sql_query.value(8).toFloat();
        if (sql_query.value(8) > 2) {
            if (r/a >= 0.8) {
                QString subOrder = QString("update %1 set wordTags=5 where word='%2'").arg(sign_in_account).arg(sql_query.value(0).toString());
                QSqlQuery sub_query(database);
                sub_query.exec(subOrder);
            }
            else if (r/a >= 0.6 && r/a < 0.8) {
                QString subOrder = QString("update %1 set wordTags=4 where word='%2'").arg(sign_in_account).arg(sql_query.value(0).toString());
                QSqlQuery sub_query(database);
                sub_query.exec(subOrder);
            }
            else if (r/a < 0.6) {
                QString subOrder = QString("update %1 set wordTags=3 where word='%2'").arg(sign_in_account).arg(sql_query.value(0).toString());
                QSqlQuery sub_query(database);
                sub_query.exec(subOrder);
            }
        }
    }
}

c2e::~c2e()
{
    delete ui;
}

void c2e::on_back_clicked()
{
    this->close();
    memory *Memory = new memory();
    Memory->memorize_tool_init(sign_in_account);
    Memory->show();
}

void c2e::on_c1_clicked()
{
    if (0 != ans_index) right_or_not = 0;
    judgement(0, ans_index, right_or_not);
}

void c2e::on_c2_clicked()
{
    if (1 != ans_index) right_or_not = 0;
    judgement(1, ans_index, right_or_not);
}

void c2e::on_c3_clicked()
{
    if (2 != ans_index) right_or_not = 0;
    judgement(2, ans_index, right_or_not);
}

void c2e::on_c4_clicked()
{
    if (3 != ans_index) right_or_not = 0;
    judgement(3, ans_index, right_or_not);
}
