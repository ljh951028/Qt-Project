#include <QCoreApplication>

#include "simplefactory.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ChoseCommodity *c = new ChoseCommodity;
    Commodity *commodity = nullptr;

    commodity = c->create("Water");
    commodity->getPrice();

    commodity = c->create("Milk");
    commodity->getPrice();

    commodity = c->create("CoKe");
    commodity->getPrice();

    return a.exec();
}
