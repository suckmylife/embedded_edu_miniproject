#ifndef __YEBBIX_SHOP_H__
#define __YEBBIX_SHOP_H__

#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>

#include "../yebbixDatabase/buyDB.h"
#include "../yebbixDatabase/productDB.h"
#include "../yebbixDatabase/LicenseDB.h"

#include "../yebbixLogin.h"
#include "../yebbixUI.h"
#include "../yebbixmanager.h"

#include "yebbixClientMain.h"
using namespace std;

class YebbixShop : public YebbixUI
{
public:
    static YebbixShop* getInstance() {
        if (!instance)
            instance = new YebbixShop();
        return instance;
    }
    
    void show() override;
    void buy_view();

    vector<string> getBuyInfo();
    static void destroyInstance();

    string getOrderNum(){return order_num;};
    void setOrderNum(const string &o){order_num = o;};
    ~YebbixShop();
private:
    static YebbixShop* instance;
    BuyDB *buy_db;
    ProductDB *product_db;
    LicenseDB *license_db;
    vector<vector<string>> license_table;
    string order_num;

    YebbixShop();
};

#endif //__YEBBIX_CLIENT_MAIN_H__