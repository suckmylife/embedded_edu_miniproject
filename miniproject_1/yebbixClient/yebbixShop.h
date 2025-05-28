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

using namespace std;

class YebbixShop 
{
public:
    static YebbixShop* getInstance() {
        if (!instance)
            instance = new YebbixShop();
        return instance;
    }
    
    void show();
    void buy_view();

    vector<vector<string>> getBuyInfo();

    ~YebbixShop();
private:
    static YebbixShop* instance;
    BuyDB *buy_db;
    ProductDB *product_db;
    LicenseDB *license_db;
    vector<vector<string>> license_table;
    string order_num;

    YebbixShop(){
        buy_db = new BuyDB();
        product_db = new ProductDB();
        license_db = new LicenseDB();
    };
};

#endif //__YEBBIX_CLIENT_MAIN_H__