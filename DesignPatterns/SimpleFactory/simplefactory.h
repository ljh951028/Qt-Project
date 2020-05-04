#ifndef SIMPLEFACTORY_H
#define SIMPLEFACTORY_H

#include <QDebug>

class Commodity
{
public:
    virtual void getPrice() = 0;
protected:
    ~Commodity(){}
};

class Water : public Commodity
{
public:
    virtual void getPrice()
    {
        qDebug()<<"Water Price: 2.5";
    }
protected:
    ~Water(){}
};

class Milk : public Commodity
{
public:
    virtual void getPrice()
    {
        qDebug()<<"Milk Price: 4";
    }
protected:
    ~Milk(){}
};

class CoKe : public Commodity
{
public:
    virtual void getPrice()
    {
        qDebug()<<"CoKe Price: 3";
    }
protected:
    ~CoKe(){}
};

class ChoseCommodity
{
public:
    Commodity *create(const QString &commodity)
    {
        if(commodity=="Water")
        {
            return new Water;
        }
        else if (commodity=="Milk")
        {
            return new Milk;
        }
        else if (commodity=="CoKe")
        {
            return new CoKe;
        }
        else
        {
            qDebug()<<"dont have this commodity!";
            return nullptr;
        }
    }
};

#endif // SIMPLEFACTORY_H
