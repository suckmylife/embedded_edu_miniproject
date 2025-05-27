#ifndef __YEBBIX_MAIN_H__
#define __YEBBIX_MAIN_H__

#include <iostream>
#include "yebbixLogin.h"
#include "yebbixJoin.h"
using namespace std;

class YebbixMain
{
public:
    YebbixMain();
    void show();
    ~YebbixMain();
private:
    YebbixLogin *login;
    YebbixJoin *join;


};

#endif //__YEBBIX_MAIN_H__