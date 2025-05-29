#ifndef __YEBBIX_CLIENT_MAIN_H__
#define __YEBBIX_CLIENT_MAIN_H__

#include <iostream>
#include <vector>
#include <cstdlib>

#include "yebbixShop.h"
#include "yebbixRecord.h"
#include "yebbixShop.h"
#include "../yebbixUI.h"

using namespace std;

class YebbixClientMain : public YebbixUI
{
public:
    static YebbixClientMain* getInstance() {
        if (!instance)
            instance = new YebbixClientMain();
        return instance;
    }
    
    void show() override;
    int WhatRank();
    //기능
    void license_shop();
    void version_select();

    ~YebbixClientMain();
private:
    static YebbixClientMain* instance;
    YebbixClientMain(){};

    enum Rank{
        VIEWER,
        PRO,
        UNRANK
    };

    void viewer_view();
    void pro_view();
    void unrank_view();

    int userRank;
};

#endif //__YEBBIX_CLIENT_MAIN_H__