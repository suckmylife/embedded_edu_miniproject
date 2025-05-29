#ifndef __YEBBIX_MAIN_H__
#define __YEBBIX_MAIN_H__

#include <iostream>
#include "yebbixLogin.h"
#include "yebbixJoin.h"
#include "yebbixUI.h"
using namespace std;

class YebbixMain : public YebbixUI
{
public:
    static YebbixMain* getInstance() {
        if (!instance)
            instance = new YebbixMain();
        return instance;
    }
    void show() override;
    ~YebbixMain();
private:
    static YebbixMain* instance;
    YebbixMain(){};
};

#endif //__YEBBIX_MAIN_H__