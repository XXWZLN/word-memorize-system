#ifndef E2C_H
#define E2C_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "memory.h"

#define level1 0.6
#define level2 0.3
#define level3 0.05
#define level4 0.05

namespace Ui {
class e2c;
}

class e2c : public QWidget
{
    Q_OBJECT

public:
    explicit e2c(QWidget *parent = nullptr);
    void e2cInit(QString account, int _words_num);
    int level_num(int level);
    int level_select();
    int word_select(int level);
    ~e2c();

private slots:
    void on_back_clicked();

private:
    Ui::e2c *ui;
    QString sign_in_account;
    QSqlDatabase database;
    QSqlQuery sql_query;
    int words_num;
    int remb_level_1;
    int remb_level_2;
    int remb_level_3;
    int remb_level_4;
    int word_index;
    //int remb_level;
};

#endif // E2C_H
