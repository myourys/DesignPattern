/*=============================================================================
#     FileName: Singletion.h
#         Desc: 单例模式
#       Author: Hector
#        Email: myourys@gmail.com
#     HomePage: http://www.yiwuye.com
#      Version: 0.0.1
#   LastChange: 2013-11-23 16:29:23
#      History: 列举各种实现单例模式的优缺点，实际使用根据情况进行改进
=============================================================================*/
/*
 * 单例模式
 * 单例模式只运行应用程序创建唯一一个类的实例，多用与全局资源共享
 * 参考资料 http://blog.csdn.net/wansbest/article/details/8664764
 */
#ifndef _SINGLETION_H
#define _SINGLETION_H

#include <pthread.h>

/****************************
 * 版本一：
 * 1. 非线程安全
 * 2. 禁止外部创建、拷贝、析构
 * 3. 利用私有静态变量自动释放内存
 *
 ***************************/
class Singletion
{
public:
    static Singletion* GetInstance(); //获取唯一实例
    void test();
private:
    Singletion(){}; //私有构造函数，保证实例的唯一性，未避免子类多个实例，不允许继承
    Singletion(const Singletion &t){}; //禁止拷贝
    ~Singletion(){std::cout<<"~Singletion called;"<<std::endl;};  //可以考虑私有化，不允许外界delete

private:
    static Singletion* m_pSingle;

    class CGarbo{ //垃圾工人
            public:
                ~CGarbo()
                {
                    if(Singletion::m_pSingle)
                        delete m_pSingle;
                }
        };
    static CGarbo m_Garbo; //利用静态成员会在程序结束时自动释放其内存的原理，调用delete

};

Singletion* Singletion::m_pSingle = NULL; //静态成员需要在类体外初始化

Singletion* Singletion::GetInstance()
{
    if(NULL == m_pSingle)
        m_pSingle = new Singletion();
    return m_pSingle;
}

void Singletion::test()
{
    std::cout<<"Singletion test"<<std::endl;
}

/*****************************************
 * 版本二
 * 在应用程序初始化时候直接实例化一个，这样能确保线程安全
 * 但是这样在应用程序时就创建了对象，似乎也不太好
 *
 *****************************************/

class SingletionSafe
{
public:
    static SingletionSafe* GetInstance(); //获取唯一实例
    void test();

private:
    SingletionSafe(){}; //私有构造函数，保证实例的唯一性，未避免子类多个实例，不允许继承
    SingletionSafe(const SingletionSafe &t){}; //禁止拷贝
private:
    static SingletionSafe *m_pSingle;

};

SingletionSafe* SingletionSafe::m_pSingle = new SingletionSafe(); //应用程序初始时直接实例化一个
SingletionSafe* SingletionSafe::GetInstance()
{
    return m_pSingle;
}

void SingletionSafe::test()
{
    std::cout<<"SingletionSafe test"<<std::endl;
}

/*******************************************************
 * 版本三
 * 利用多线程锁解决线程安全问题
 *
 ******************************************************/

class MyLock
{
private:
    pthread_mutex_t m_mutex;
public:
    MyLock(){pthread_mutex_init(&m_mutex,NULL);};
    virtual ~MyLock(){pthread_mutex_destroy(&m_mutex);};
    int Lock(){return pthread_mutex_lock(&m_mutex);};
    int unLock(){return pthread_mutex_unlock(&m_mutex);};
};

class SingletionThread
{
public:
    static SingletionThread* GetInstance(); //获取唯一实例
    void test();

private:
    SingletionThread(){}; //私有构造函数，保证实例的唯一性，未避免子类多个实例，不允许继承
    SingletionThread(const SingletionThread &t){}; //禁止拷贝
private:
    static SingletionThread *m_pSingle;

};

SingletionThread* SingletionThread::m_pSingle = NULL;
MyLock Lock; //创建并初始化锁

SingletionThread* SingletionThread::GetInstance()
{
    if(NULL == m_pSingle)
    {
        Lock.Lock();
        if(NULL == m_pSingle)
            m_pSingle = new SingletionThread();
        Lock.unLock();
    }
    return m_pSingle;
}

void SingletionThread::test()
{
    std::cout<<"SingletionThread test"<<std::endl;
}


#endif
