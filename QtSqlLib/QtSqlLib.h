#ifndef QTSQLLIB_H
#define QTSQLLIB_H

#include "qtsqllib_global.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <Windows.h>
#include <QString>
#include <QMap>

#define SQL_STATE_CODE_BASE         0x00000000

#define SQL_STATE_SUCCESS           (SQL_STATE_CODE_BASE+1)
#define SQL_CREATE_DATABASE         (SQL_STATE_CODE_BASE+2)
#define SQL_CREATE_TABLE            (SQL_STATE_CODE_BASE+3)
#define SQL_INSERT_DATA             (SQL_STATE_CODE_BASE+4)
#define SQL_DELETE_DATA             (SQL_STATE_CODE_BASE+5)
#define SQL_UPDATA_DATA             (SQL_STATE_CODE_BASE+6)

class QTSQLLIBSHARED_EXPORT QtSqlLib
{

public:
    QtSqlLib();
    ~QtSqlLib();

    DWORD CreateSql(QString name,const QString &type);
    DWORD CreateTable(QString tableName,QMap<QString,QString> map);

    DWORD InsertData(QString tableName, QStringList arguments, QStringList data);
    DWORD DeleteData(QString tableName, QString key, QString value);
    DWORD DeleteData(QString tableName, QString condition);
    DWORD UpdateData(QString tableName,
                     QString updateKey,
                     QString updateValue,
                     QString findKey,
                     QString findValue);

    bool isTableExist(QString table);

private:
    QSqlDatabase db;
};

#endif // QTSQLLIB_H
