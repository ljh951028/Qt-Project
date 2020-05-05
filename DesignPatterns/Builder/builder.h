#ifndef BUILDER_H
#define BUILDER_H

#include <QDebug>

class Product
{
public:
    Product(){}
    ~Product(){}

    void setA(QString A) {
        this->m_A = A;
    }

    void setB(QString B) {
        this->m_B = B;
    }

    void setC(QString C) {
        this->m_C = C;
    }

    void show(){
        qDebug()<<m_A<<endl
               <<m_B<<endl
              <<m_C;
    }

private:
    QString m_A;
    QString m_B;
    QString m_C;
};

class AbstractBuilder{
public:
    AbstractBuilder(){}
    virtual ~AbstractBuilder(){}

    virtual void createProduct() = 0;
    virtual void buildPartA(QString param) = 0;
    virtual void buildPartB(QString param) = 0;
    virtual void buildPartC(QString param) = 0;

    virtual Product* getProduct() = 0;
};

class Builder: public AbstractBuilder{
public:
    Builder(){}
    ~Builder(){}

    void createProduct() {
        m_product = new Product;
    }

    void buildPartA(QString param) {
        m_product->setA(param);
    }

    void buildPartB(QString param) {
        m_product->setB(param);
    }

    void buildPartC(QString param) {
        m_product->setC(param);
    }

    Product* getProduct() {
        return m_product;
    }

private:
    Product* m_product;

};

class Director
{
public:
    Director(AbstractBuilder* builder) {
        m_builder = builder;
    }
    ~Director() {}

    void construct() {
        if(!m_builder)
            return;
        m_builder->buildPartA("A");
        m_builder->buildPartB("B");
        m_builder->buildPartC("C");
    }

private:
    AbstractBuilder* m_builder;
};

#endif // BUILDER_H
