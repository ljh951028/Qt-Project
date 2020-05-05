#include <QCoreApplication>
#include "builder.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Builder *builder = new Builder;
    Director *director = new Director(builder);

    builder->createProduct();
    director->construct();

    Product *product = builder->getProduct();
    product->show();

    return a.exec();
}
