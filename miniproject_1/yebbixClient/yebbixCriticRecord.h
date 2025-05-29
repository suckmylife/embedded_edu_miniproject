#ifndef __YEBBIX_CRITIC_RECORD_H__
#define __YEBBIX_CRITIC_RECORD_H__

#include <iostream>
#include <vector>
#include <iomanip>

#include "../yebbixDatabase/RecordDB.h"

#include "../yebbixLogin.h"
#include "../yebbixUI.h"
#include "../yebbixmanager.h"

using namespace std;

class YebbixCriticRecord : public YebbixUI
{
public:
    static YebbixCriticRecord* getInstance() {
        if (!instance)
            instance = new YebbixCriticRecord();
        return instance;
    }
    
    void show() override;
    static void destroyInstance();
    ~YebbixCriticRecord();
private:
    static YebbixCriticRecord* instance;
    vector<vector<string>> all_table;
    RecordDB *record_db;
    YebbixCriticRecord(){record_db = new RecordDB();}
};

#endif //__YEBBIX_CRITIC_RECORD_H__