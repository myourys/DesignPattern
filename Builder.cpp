/*=============================================================================
#     FileName: Builder.cpp
#         Desc: 建造者模式
#       Author: Hector
#        Email: myourys@gmail.com
#     HomePage: http://www.yiwuye.com
#      Version: 0.0.1
#   LastChange: 2013-11-23 22:24:58
#      History:
=============================================================================*/

/*
 * 建造者模式适合复杂对象的构造
 * 如一个人，有男人，女人，但是人都有head,body,foot
 */

#include <iostream>
#include <string.h>
using namespace std;

//定义产品结构
class Person
{
public:
    void setHead(string s_head){m_head = s_head;};
    void setBody(string s_body){m_body = s_body;};
    void setFoot(string s_foot){m_foot = s_foot;};
    void show(){cout<<"Persion:"<<endl;cout<<"Head is =>"<<m_head<<endl;cout<<"Body is =>"<<m_body<<endl;cout<<"Foot is =>"<<m_foot<<endl<<endl;};
private:
    string m_head;
    string m_body;
    string m_foot;
};

//抽象的构造者类
class AbstractBuilder
{
public:
    virtual void createPerson() = 0;
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildFoot() = 0;
    virtual Person* getPerson() = 0;
};

//导演者类，生成产品（人）
class Director
{
public:
    void assign(AbstractBuilder* builder){m_builder = builder;};
    void construct();
private:
    AbstractBuilder* m_builder;
};

void Director::construct()
{
    if(!m_builder)
        return;
    m_builder->createPerson();
    m_builder->buildHead();
    m_builder->buildBody();
    m_builder->buildFoot();
}

//男人构造者类
class ManBuilder:public AbstractBuilder
{
public:
    void createPerson(){m_person = new Person();};
    void buildHead(){m_person->setHead("智慧的男人头");};
    void buildBody(){m_person->setBody("强壮的男人身体");};
    void buildFoot(){m_person->setFoot("一双男人的大脚");};
    Person* getPerson(){return m_person;};
private:
    Person* m_person;
};

//女人构造者类
class WomanBuilder:public AbstractBuilder
{
public:
    void createPerson(){m_person = new Person();};
    void buildHead(){m_person->setHead("漂亮的女人脸蛋");};
    void buildBody(){m_person->setBody("妖娆的女人身体");};
    void buildFoot(){m_person->setFoot("小巧的秀脚");};
    Person* getPerson(){return m_person;};
private:
    Person* m_person;
};

int main()
{
    Director director;

    AbstractBuilder* manBuilder = new ManBuilder();
    director.assign(manBuilder);
    director.construct();
    Person* man = manBuilder->getPerson();
    man->show();

    AbstractBuilder* womanBuilder = new WomanBuilder();
    director.assign(womanBuilder);
    director.construct();
    Person* woman = womanBuilder->getPerson();
    woman->show();

    delete manBuilder;
    delete womanBuilder;
    delete man;
    delete woman;
    return 0;
}
