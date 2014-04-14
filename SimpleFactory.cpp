/*=============================================================================
#     FileName: SimpleFactory.cpp
#         Desc: 简单工厂模式
#       Author: Hector
#        Email: myourys@gmail.com
#     HomePage: http://www.yiwuye.com
#      Version: 0.0.1
#   LastChange: 2013-11-24 16:09:55
#      History:
=============================================================================*/
/*
 *   简单工厂模式
 *   如手机都有一个抽象的打电话功能，苹果手机，nokia手机都继承这个手机
 *   简单工厂根据客户的要求，看生产什么品牌的手机
 */


#include <iostream>
#include <string>
using namespace std;

//抽象的手机类
class Phone
{
public:
    virtual void doCall(const string& number) = 0; //打电话
};

//工厂制造类
class SimpleFactory
{
public:
    static Phone* createPhone(const string& model);
};
//nokia手机
class Nokia:public Phone
{
public:
    void doCall(const string& number){cout<<"用诺基亚拨打号码:"<<number<<endl;};
};
//苹果手机
class Apple:public Phone
{
public:
    void doCall(const string& number){cout<<"用苹果手机拨打号码:"<<number<<endl;};
};

Phone* SimpleFactory::createPhone(const string& model)
{
    if(model == "Nokia")
        return new Nokia();
    else if (model == "Apple")
        return new Apple();
    else
        return NULL;
}

int main()
{
    Phone* nokia = SimpleFactory::createPhone("Nokia");
    nokia->doCall("13988888888");

    Phone* apple = SimpleFactory::createPhone("Apple");
    apple->doCall("158999999999");

    delete nokia;
    delete apple;
    return 0;
}
