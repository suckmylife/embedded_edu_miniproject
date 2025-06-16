#ifndef __YEBBIX_WARN_RECORD_H__
#define __YEBBIX_WARN_RECORD_H__

#include <iostream>
#include <vector>
#include <iomanip>

#include "../yebbixDatabase/RecordDB.h"

#include "../yebbixUserManager.h"
#include "../yebbixUI.h"
#include "../yebbixmanager.h"

using namespace std;

class YebbixWarnRecord : public YebbixUI
{
public:
    static YebbixWarnRecord* getInstance() {
        if (!instance)
            instance = new YebbixWarnRecord();
        return instance;
    }
    
    void show() override;
    static void destroyInstance();
    ~YebbixWarnRecord();
private:
    static YebbixWarnRecord* instance;
    vector<vector<string>> all_table;
    RecordDB *record_db;
    YebbixWarnRecord();
};

#endif //__YEBBIX_CLIENT_MAIN_H__