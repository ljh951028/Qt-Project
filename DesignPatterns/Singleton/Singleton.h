#ifndef SINGLETON_H
#define SINGLETON_H

#include <QMutex>
#include <QDebug>
#include <QAtomicPointer>

//
// 单例模板-双重锁检测
//
template<typename T>
class Singleton
{
public:
    static T* Instance()
    {

        QMutexLocker mutexLocker(&s_lock);
        if(m_instance.testAndSetOrdered(0,0))
        {
            m_instance.testAndSetOrdered(0, new T);
        }

        return m_instance;
    }

    static void release()
    {
        QMutexLocker mutexLocker(&s_lock);
        m_instance.fetchAndStoreOrdered(0);
    }

private:
    Q_DISABLE_COPY(Singleton)

private:
    static QMutex s_lock;
    static QAtomicPointer<T> m_instance;
};

template <typename T>
QAtomicPointer<T> Singleton<T>::m_instance;

template <typename T>
QMutex Singleton<T>::s_lock;


class testClass
{
private:
    testClass(){}

    friend class Singleton<testClass>;

public:
    void print(){qDebug()<<"aab";}
};

#endif // SINGLETON_H
