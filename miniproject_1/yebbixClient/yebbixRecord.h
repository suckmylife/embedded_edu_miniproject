#ifndef __YEBBIX_RECORD_H__
#define __YEBBIX_RECORD_H__

#include <iostream>
#include <vector>
#include <iomanip>
#include "../yebbixDatabase/RecordDB.h"
#include "../yebbixLogin.h"
using namespace std;

class YebbixRecord
{
public:
    static YebbixRecord* getInstance() {
        if (!instance)
            instance = new YebbixRecord();
        return instance;
    }
    
    void show();

    //기능
    void all_record_check();
    void warning_record_check();
    void critical_record_check();

    ~YebbixRecord();
private:
    static YebbixRecord* instance;
    vector<vector<string>> all_table;
    RecordDB *record_db;
    YebbixRecord(){record_db = new RecordDB();}
};

#endif //__YEBBIX_CLIENT_MAIN_H__