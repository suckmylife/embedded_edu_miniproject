#ifndef __YEBBIX_RECORD_H__
#define __YEBBIX_RECORD_H__

#include <iostream>
#include <vector>
#include <iomanip>

#include "../yebbixDatabase/RecordDB.h"

#include "../yebbixLogin.h"
#include "../yebbixUI.h"
#include "../yebbixmanager.h"

using namespace std;

class YebbixRecord : public YebbixUI
{
public:
    static YebbixRecord* getInstance() {
        if (!instance)
            instance = new YebbixRecord();
        return instance;
    }
    
    void show() override;
    static void destroyInstance();
    ~YebbixRecord();
private:
    static YebbixRecord* instance;
    vector<vector<string>> all_table;
    RecordDB *record_db;
    YebbixRecord();
};

#endif //__YEBBIX_CLIENT_MAIN_H__