#ifndef MYSQLTABLEMODEL_H
#define MYSQLTABLEMODEL_H

#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>



class MySqlTableModel : public QSqlTableModel
{
public:
    MySqlTableModel(QObject *parent, QSqlDatabase db);
    bool MySelect(QString query);
private:
//    QSqlQuery qu;
    QSqlDatabase database;
};

#endif // MYSQLTABLEMODEL_H
