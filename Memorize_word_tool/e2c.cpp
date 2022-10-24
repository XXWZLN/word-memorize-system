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

void e2c::level_num_all()
{
    for(int i = 0; i < 6; i++)
    {
        remb_level[i] = level_num(i);
    }
}




void e2c::level_num_config()
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

int e2c::level_select()
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

int e2c::word_select(int level)
{
    if(level == -1)
    {
        qDebug() << "背完了";
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

void e2c::words_init(QString word)
{
    ui->label->setText(word);
    QString subOrder = QString("select * from %1 where word='%2'").arg(sign_in_account).arg(word);
    sql_query.exec(subOrder);
    sql_query.first();
    QString wa = sql_query.value(1).toString();
    QString order1 = QString("select meaning from %1 where word='%2'").arg(sign_in_account).arg(sql_query.value(4).toString());
    QString order2 = QString("select meaning from %1 where word='%2'").arg(sign_in_account).arg(sql_query.value(5).toString());
    QString order3 = QString("select meaning from %1 where word='%2'").arg(sign_in_account).arg(sql_query.value(6).toString());
    sql_query.exec(order1);
    sql_query.first();
    QString w1 = sql_query.value(0).toString();
    sql_query.exec(order2);
    sql_query.first();
    QString w2 = sql_query.value(0).toString();
    sql_query.exec(order3);
    sql_query.first();
    QString w3 = sql_query.value(0).toString();
    QVector<QString> words;
    words.append(wa);
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

void e2c::judgement(int n, int ans, int right_or_not)
{
    if (n == ans && right_or_not == 1) {
        //"update %1 set rem_num = rem_num + 1 all_num = all_num + 1 where word = '%2'"
        QString order = QString ("update %1 set rem_num=rem_num+1,all_num=all_num+1 where word='%2'").arg(sign_in_account).arg(word_now);
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
        right_or_not = 0;
    }
    else if (n == ans && right_or_not == 0){
        QString order = QString ("update %1 set all_num=all_num+1 where word='%2'").arg(sign_in_account).arg(word_now);
        sql_query.exec(order);
        ui->error->setText("");
        right_or_not = 1;
        int l;
        l = level_select();
        while(!word_select(l))
        {
            l = level_select();
        }
        words_init(word_now);
        }
}

e2c::~e2c()
{
    delete ui;
}

void e2c::on_back_clicked()
{
//    for(auto &x : remb_level_expect)
//        qDebug() << x;
//    level_num_all();
//    for(auto &x : remb_level)
//        qDebug() << x;
//    level_num_config();
//    for(auto &x : remb_level)
//        qDebug() << x;

//    this->close();
//    wordslibrary *Wordslibrary = new wordslibrary();
//    Wordslibrary->sqlInit(sign_in_account);
//    Wordslibrary->show();



//    int l;
//    level_num_all();
//    level_num_config();


    int l;
    l = level_select();
    while(!word_select(l))
    {
        l = level_select();
    }
    words_init(word_now);



    //words_init()

//    Py_SetPythonHome(L"C:\\Anaconda\\envs\\nltk_x32");
//    Py_Initialize();
//    PyRun_SimpleString("import sys");
//    PyRun_SimpleString("sys.path.append('D:/QtProject/Memorize_word_tool/build-Memorize_word_tool-Desktop_Qt_5_9_9_MinGW_32bit-Debug')");
//    PyRun_SimpleString("print(sys.path)");
//    PyObject* pModule = PyImport_ImportModule("sayHello");
//    PyObject* pFunc = PyObject_GetAttrString(pModule, "say");
//    PyObject* pargs = PyTuple_New(1);
//    PyTuple_SetItem(pargs, 0, Py_BuildValue("i", 100));
//    PyObject* ans = PyObject_CallObject(pFunc, pargs);
//    long ans_c = PyLong_AsLong(ans);
//    qDebug() << ans_c;
//    Py_Finalize();
}











//void e2c::level_num_all(QVector<item>& lnv)
//{
//    for(int i = 0; i < 6; i++)
//    {
//        tem.key = i;
//        tem.elem = level_num(i);
//        lnv.append(tem);
//    }
//}

//void e2c::vector_order(QVector<item> &level_num)
//{
//    for(int i = 0; i < level_num.size() - 1; i++)
//    {
//        for(int j = 0; j <level_num.size() - 1 - i ; j++)
//            if(level_num[j].elem > level_num[j + 1].elem)
//            {
//                tem.elem = level_num[j].elem;
//                tem.key = level_num[j].key;
//                level_num[j].elem = level_num[j + 1].elem;
//                level_num[j].key = level_num[j + 1].key;
//                level_num[j + 1].key = tem.key;
//                level_num[j + 1].elem = tem.elem;
//            }
//    }
//}

void e2c::on_c1_clicked()
{
    if (0 != ans_index) right_or_not = 0;
    judgement(0, ans_index, right_or_not);
}

void e2c::on_c2_clicked()
{
    if (1 != ans_index) right_or_not = 0;
    judgement(1, ans_index, right_or_not);
}

void e2c::on_c3_clicked()
{
    if (2 != ans_index) right_or_not = 0;
    judgement(2, ans_index, right_or_not);
}

void e2c::on_c4_clicked()
{
    if (3 != ans_index) right_or_not = 0;
    judgement(3, ans_index, right_or_not);
}
