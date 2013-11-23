/*=============================================================================
#     FileName: Singletion.cpp
#         Desc: 单例模式
#       Author: Hector
#        Email: myourys@gmail.com
#     HomePage: http://www.yiwuye.com
#      Version: 0.0.1
#   LastChange: 2013-11-23 16:45:00
#      History:
=============================================================================*/

#include <iostream>
#include "Singletion.h"

int main()
{
    Singletion* pSingle = Singletion::GetInstance();
    //Singletion* pSingle2 = new Singletion(); //error
    //Singletion single = *pSingle; //error 
    pSingle->test();


    SingletionSafe* pSafe = SingletionSafe::GetInstance();
    pSafe->test();

    SingletionThread* pSingleThread = SingletionThread::GetInstance();
    pSingleThread->test();
    return 0;
}

