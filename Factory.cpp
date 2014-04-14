/*=============================================================================
#     FileName: Factory.cpp
#         Desc: 工厂模式
#       Author: Hector
#        Email: myourys@gmail.com
#     HomePage: http://www.yiwuye.com
#      Version: 0.0.1
#   LastChange: 2013-11-24 16:36:05
#      History:
=============================================================================*/
/*
 *   工厂模式
 *   如手机都有一个抽象的打电话功能，苹果手机，nokia手机都继承这个手机
 *   这时需要一个苹果手机工厂生产苹果手机Iphone4,iphone5，nokia手机工厂生产nikia手机N95,Lumia900
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

//N95
class N95:public Phone
{
public:
    void doCall(const string& number){cout<<"用诺基亚N95拨打号码:"<<number<<endl;};
};

//Lumia900
class Lumia900:public Phone
{
public:
    void doCall(const string& number){cout<<"用诺基亚Lumia900拨打号码:"<<number<<endl;};
};


//苹果Iphone4
class Iphone4:public Phone
{
public:
    void doCall(const string& number){cout<<"用Iphone4拨打号码:"<<number<<endl;};
};

//苹果Iphone5
class Iphone5:public Phone
{
public:
    void doCall(const string& number){cout<<"用Iphone5拨打号码:"<<number<<endl;};
};



//工厂制造类
class Factory
{
public:
    virtual Phone* createPhone(const string& model) = 0;
};

//Nokia工厂
class NokiaFactory:Factory
{
public:
     Phone* createPhone(const string& model);
};

//Apple工厂
class AppleFactory:Factory
{
public:
     Phone* createPhone(const string& model);
};



Phone* NokiaFactory::createPhone(const string& model)
{
    if(model == "N95")
        return new N95();
    else if (model == "Lumia900")
        return new Lumia900();
    else
    return NULL;
}

Phone* AppleFactory::createPhone(const string& model)
{
    if(model == "Iphone4")
        return new Iphone4();
    else if (model == "Iphone5")
        return new Iphone5();
    else
        return NULL;
}



int main()
{
    NokiaFactory nokia;
    Phone* n95 = nokia.createPhone("Lumia900");
    n95->doCall("13988888888");

    AppleFactory apple;
    Phone* iphone5 = apple.createPhone("Iphone5");
    iphone5->doCall("158999999999");

    delete n95;
    delete iphone5;
    return 0;
}
