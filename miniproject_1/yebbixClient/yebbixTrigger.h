#ifndef __YEBBIX_TRIGGER_H__
#define __YEBBIX_TRIGGER_H__

#include <iostream>
#include <vector>
#include <iomanip>

#include "../yebbixDatabase/triggerDB.h"

#include "../yebbixLogin.h"
#include "../yebbixUI.h"
#include "../yebbixmanager.h"

using namespace std;

class YebbixTrigger : public YebbixUI
{
public:
    static YebbixTrigger* getInstance() {
        if (!instance)
            instance = new YebbixTrigger();
        return instance;
    }
    
    void show() override;
    static void destroyInstance();
    ~YebbixTrigger();
private:
    static YebbixTrigger* instance;
    vector<vector<string>> all_table;
    TriggerDB *trigger_db;
    YebbixTrigger();
};

#endif //__YEBBIX_TRIGGER_H__