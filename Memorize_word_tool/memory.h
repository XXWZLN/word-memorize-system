#ifndef MEMORY_H
#define MEMORY_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "wordslibrary.h"
#include "e2c.h"
#include "c2e.h"

namespace Ui {
class memory;
}

class memory : public QWidget
{
    Q_OBJECT

public:
    explicit memory(QWidget *parent = nullptr);
    ~memory();
    void memorize_tool_init(QString account);

private slots:
    void on_back_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::memory *ui;
    QSqlDatabase database;
    QSqlQuery sql_query;
    QString sign_in_account;
};

#endif // MEMORY_H
