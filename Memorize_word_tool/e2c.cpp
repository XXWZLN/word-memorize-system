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
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(QApplication::applicationDirPath() + "/data.db");
    if(!database.open())
    {
        qDebug()<<"error";
    }

    sql_query = QSqlQuery(database);

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
        qDebug()<<sql_query.value(0);

    }
    qDebug() << "next";
    if(row == 0)
        return 0;
    row = rand() % row;
    sql_query.first();
    for(int j = 0; j < row; j++)
    {
        sql_query.next();
    }
    qDebug()<<sql_query.value(0).toString();
    order = QString("update %1 set chosen = 1 where word = '%2'").arg(sign_in_account).arg(sql_query.value(0).toString());
    sql_query.exec(order);
    remb_level[level]--;
    words_num--;
    return 1;
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
//    l = level_select();
//    while(!word_select(l))
//    {
//        l = level_select();
//    }
    Py_SetPythonHome(L"C:\\Anaconda\\envs\\nltk");
    Py_Initialize();
    PyRun_SimpleString("import sys");

    PyRun_SimpleString("sys.path.append('D:/QtProject/Memorize_word_tool/build-Memorize_word_tool-Desktop_Qt_5_9_9_MinGW_32bit-Debug')");
    PyRun_SimpleString("print(sys.path)");
    PyObject* pModule = PyImport_ImportModule("sayHello");
    PyObject* pFunc = PyObject_GetAttrString(pModule, "say");
    PyObject* pargs = PyTuple_New(1);
    PyTuple_SetItem(pargs, 0, Py_BuildValue("i", 100));
    PyObject* ans = PyObject_CallObject(pFunc, pargs);
    long ans_c = PyLong_AsLong(ans);
    qDebug() << ans_c;
    Py_Finalize();



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
