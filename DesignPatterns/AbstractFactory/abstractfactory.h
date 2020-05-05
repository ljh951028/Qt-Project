#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <QDebug>

class Shop
{
public:
    virtual void name() = 0;
protected:
    ~Shop(){}
};

class AbstractFactory
{
public:
    virtual Shop *createA() = 0;
    virtual Shop *createB() = 0;

protected:
    ~AbstractFactory(){}
};

class Milk : public Shop
{
public:
    virtual void name(){
        qDebug()<<"milk";
    }
protected:
    ~Milk(){}
};

class Water : public Shop
{
public:
    virtual void name(){
        qDebug()<<"Water";
    }
protected:
    ~Water(){}
};

class Meat : public Shop
{
public:
    virtual void name(){
        qDebug()<<"Meat";
    }
protected:
    ~Meat(){}
};

class Vegetables : public Shop
{
public:
    virtual void name(){
        qDebug()<<"Vegetables";
    }
protected:
    ~Vegetables(){}
};

class Drink : public AbstractFactory
{
public:
    virtual Shop *createA(){
        return new Milk;
    }

    virtual Shop *createB(){
        return new Water;
    }

protected:
    ~Drink(){}
};

class Food : public AbstractFactory
{
public:
    virtual Shop *createA(){
        return new Meat;
    }

    virtual Shop *createB(){
        return new Vegetables;
    }

protected:
    ~Food(){}
};


#endif // ABSTRACTFACTORY_H
