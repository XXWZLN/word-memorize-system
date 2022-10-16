#include "mysqltablemodel.h"


MySqlTableModel::MySqlTableModel(QObject *parent, QSqlDatabase db)
{
    parent = 0;
    database = db;
}

bool MySqlTableModel::MySelect(QString query)
{
    //const QString queryStr = query;
    if (query.isEmpty())
        return false;
    beginResetModel();
    QSqlQuery qu(query, database);
    setQuery(qu);
    if (!qu.isActive() || lastError().isValid()) {
        // something went wrong - revert to non-select state
        //d->initRecordAndPrimaryIndex();
        endResetModel();
        return false;
    }
    endResetModel();
    return true;
}
