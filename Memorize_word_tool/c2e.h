#ifndef C2E_H
#define C2E_H

#include <Python.h>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <QVector>
#include "memory.h"

#define level0 0.25
#define level1 0.25
#define level2 0.2
#define level3 0.2
#define level4 0.1

namespace Ui {
class c2e;
}

class c2e : public QWidget
{
    Q_OBJECT

public:
    explicit c2e(QWidget *parent = nullptr);
    void c2eInit(QString account, int _words_num);
    int level_num(int level);
    //void level_num_all(QVector<item>& lnv);
    //void vector_order(QVector<item> &level_num);
    void level_num_all();
    void level_num_config();
    int level_select();
    int word_select(int level);
    void words_init(QString word);
    void judgement(int n, int ans, int right_or_not);
    void finish ();
    ~c2e();

private slots:
    void on_back_clicked();

    void on_c1_clicked();

    void on_c2_clicked();

    void on_c3_clicked();

    void on_c4_clicked();

private:
    Ui::c2e *ui;
    QString sign_in_account;
    QSqlDatabase database;
    QSqlQuery sql_query;
    int words_num;
    int remb_level_expect[6];
    int remb_level[6];
    int remb_practice_minus_expect[6];
    int word_index;
    //int remb_level;
    //QVector<item> level_num_vector;
    int cishu;
    QString word_now;
    int ans_index;
    int right_or_not;
};

#endif // C2E_H
