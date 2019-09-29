#include "QtSqlLib.h"

QtSqlLib::QtSqlLib()
{

}

QtSqlLib::~QtSqlLib()
{
    db.close();
}

DWORD QtSqlLib::CreateSql(QString name, const QString &type)
{
    if(QSqlDatabase::contains(name))
    {
        db = QSqlDatabase::database(name);
    }
    else
    {
        db = QSqlDatabase::addDatabase(type,name);
        db.setDatabaseName(name);/*
        db.setPassword("12345678");
        db.setConnectOptions("QSQLITE_CREATE_KEY");*/
    }

    if(!db.open())
    {
        return SQL_CREATE_DATABASE;
    }

    return SQL_STATE_SUCCESS;
}

DWORD QtSqlLib::CreateTable(QString tableName, QMap<QString, QString> map)
{
    QSqlQuery query = QSqlQuery(db);

    if(!isTableExist(tableName))
    {
        QString tableList = QString("create table %1(").arg(tableName);

        QMapIterator<QString,QString> iter(map);

        while(iter.hasNext())
        {
            iter.next();

            tableList.append(QString("%1 %2").arg(iter.key()).arg(iter.value()));

            if(iter.hasNext())
                tableList.append(",");
        }

        tableList.append(")");

        query.exec(tableList);
    }

    return SQL_STATE_SUCCESS;
}

DWORD QtSqlLib::InsertData(QString tableName, QStringList arguments, QStringList data)
{
    QSqlQuery query = QSqlQuery(db);

    QString request = "INSERT INTO " + tableName + " (";
    int argumentsLength = arguments.length();
    for(int i = 0; i < argumentsLength - 1; i++)
    {
        QString tmp = arguments[i] + ", ";
        request += tmp;
    }
    request += arguments[argumentsLength - 1] + ") VALUES (";
    int dataLength = data.length();
    for(int i = 0; i < dataLength - 1; i++)
    {
        QString tmp = data[i] + ", ";
        request += tmp;
    }
    request += data[dataLength - 1] + ")";

    if(query.prepare(request))
    {
        if(query.exec())
        {
            return SQL_STATE_SUCCESS;
        }
    }

    return SQL_INSERT_DATA;
}

DWORD QtSqlLib::DeleteData(QString tableName, QString key, QString value)
{
    QSqlQuery query = QSqlQuery(db);

    QString request = "DELETE FROM " + tableName + " WHERE " + key + " = " + value + ";";

    if(query.prepare(request))
    {
        if(query.exec())
        {
            return SQL_STATE_SUCCESS;
        }
    }

    return SQL_DELETE_DATA;
}

DWORD QtSqlLib::DeleteData(QString tableName, QString condition)
{
    QSqlQuery query = QSqlQuery(db);

    QString request = "DELETE FROM " + tableName + " WHERE " + condition + ";";

    if(query.prepare(request))
    {
        if(query.exec())
        {
            return SQL_STATE_SUCCESS;
        }
    }

    return SQL_DELETE_DATA;
}

DWORD QtSqlLib::UpdateData(QString tableName, QString updateKey, QString updateValue, QString findKey, QString findValue)
{
    QSqlQuery query = QSqlQuery(db);

    QString request = "UPDATE " + tableName + " SET " + updateKey + " = " + updateValue + " WHERE " + findKey + " = " + findValue;

    if(query.prepare(request))
    {
        if(query.exec())
        {
            return SQL_STATE_SUCCESS;
        }
    }

    return SQL_UPDATA_DATA;
}

bool QtSqlLib::isTableExist(QString table)
{
    QStringList tableList = db.tables(QSql::AllTables);
    return tableList.contains(table);
}
