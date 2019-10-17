#include <QCoreApplication>
#include <QVector>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    typedef struct _JSON_STRUCT
    {
        QString Name;
        int Age;
        bool Sex;
    }JSON_STRUCT;

    QVector<JSON_STRUCT> JsonList;

    JSON_STRUCT tmpData;

    for(int i = 23 ;i <= 26; i++)
    {
        tmpData.Name = QString::fromLocal8Bit("Li Junhao");
        tmpData.Age = i;
        tmpData.Sex = true;

        JsonList.append(tmpData);
    }

    int no = 0;

    QJsonArray array;

    for(auto iter : JsonList)
    {
        qDebug()<<iter.Name<<iter.Age<<iter.Sex;

        QJsonObject tmpObj;

        tmpObj.insert("Name",iter.Name);
        tmpObj.insert("Age",iter.Age);
        tmpObj.insert("Sex",iter.Sex);

        array.insert(no,tmpObj);

        no++;
    }

    QJsonObject rootObj;
    QJsonDocument document;

    rootObj.insert("list",QJsonValue(array));

    document.setObject(rootObj);

    QByteArray byteArray = document.toJson(QJsonDocument::Compact);

    QString strJson(byteArray);

    qDebug()<<strJson;

    return a.exec();
}
