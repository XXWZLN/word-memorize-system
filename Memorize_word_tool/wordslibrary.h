#ifndef WORDSLIBRARY_H
#define WORDSLIBRARY_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>

namespace Ui {
class wordslibrary;
}

class wordslibrary : public QWidget
{
    Q_OBJECT

public:
    explicit wordslibrary(QWidget *parent = nullptr);
    ~wordslibrary();
    void sqlInit(QString account);

private slots:
    void on_signOut_clicked();

    void on_add_clicked();

    void on_Delete_clicked();

private:
    Ui::wordslibrary *ui;
    QSqlDatabase database;
    QSqlQuery sql_query;
    QSqlTableModel *model;
    QString sign_in_account;
};

#endif // WORDSLIBRARY_H
