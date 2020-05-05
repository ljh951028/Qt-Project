#include <QCoreApplication>
#include "abstractfactory.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Shop *shop = nullptr;
    AbstractFactory *ab = nullptr;

    ab = new Drink;
    shop = ab->createA();
    shop->name();

    shop = ab->createB();
    shop->name();

    ab = new Food;
    shop = ab->createA();
    shop->name();

    shop = ab->createB();
    shop->name();

    return a.exec();
}
