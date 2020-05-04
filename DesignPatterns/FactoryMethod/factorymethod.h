#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include <QDebug>

class Shop
{
public:
    virtual void commodity() = 0;

protected:
    ~Shop(){}
};

class Water : public Shop
{
public:
    void commodity()
    {
        qDebug()<<"Water";
    }

protected:
    ~Water(){}
};

class Milk : public Shop
{
public:
    void commodity()
    {
        qDebug()<<"Milk";
    }

protected:
    ~Milk(){}
};

class Factory
{
public:
    virtual Shop *create() = 0;

protected:
    ~Factory(){}
};

class WaterFactory : public Factory
{
public:
    virtual Shop *create()
    {
        return new Water;
    }

protected:
    ~WaterFactory(){}
};

class MilkFactory : public Factory
{
public:
    virtual Shop *create()
    {
        return new Milk;
    }

protected:
    ~MilkFactory(){}
};

#endif // FACTORYMETHOD_H
