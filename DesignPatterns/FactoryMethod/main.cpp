#include <QCoreApplication>
#include "factorymethod.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Factory *factory = nullptr;
    Shop *shop = nullptr;

    factory = new MilkFactory;
    shop = factory->create();
    shop->commodity();

    factory = new WaterFactory;
    shop = factory->create();
    shop->commodity();

    return a.exec();
}
