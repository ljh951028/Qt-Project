#include <QCoreApplication>
#include <QDebug>

#include "Singleton.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testClass * obj1 = Singleton<testClass>::Instance();

    qDebug()<<obj1;

    obj1->print();

    Singleton<testClass>::release();

    qDebug()<<obj1;

    testClass * obj2 = Singleton<testClass>::Instance();

    qDebug()<<obj2;

    obj2->print();

    if(obj1 == obj2)
    {
        qDebug()<<"is the same";
    }
    else {
        qDebug()<<"not the same";
    }

    return a.exec();
}
