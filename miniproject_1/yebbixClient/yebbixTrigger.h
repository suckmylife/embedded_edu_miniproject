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
    void show_table(const vector<vector<string>> &table);
    void show_table(const vector<string> &table);
    void crud_view();
    void update();
    void del();
    void add();
    static void destroyInstance();

    string         getTriggerID()  {return trigger_id;}
    string         getTriggerName(){return trigger_name;}
    string         getTriggerCond(){return trigger_cond;}
    string         getTriggerStep(){return trigger_step;}
    vector<string> getCrudRow()    {return crud_row;}


    void   setTriggerID(const string &ids)      {trigger_id = ids;};
    void setTriggerName(const string &name)     {trigger_name = name;};
    void setTriggerCond(const string &cond)     {trigger_cond = cond;};
    void setTriggerStep(const string &steps)    {trigger_step = steps;};
    void setCrudRow    (const vector<string> &r){crud_row = r;};

    ~YebbixTrigger();
private:
    static YebbixTrigger* instance;
    vector<vector<string>> all_table;
    vector<string> crud_row;
    TriggerDB *trigger_db;
    string trigger_id;
    string trigger_name;
    string trigger_cond;
    string trigger_step;
    enum Rank{
        NORMAL,
        WARNING,
        CRITICAL
    };
    YebbixTrigger();
};

#endif //__YEBBIX_TRIGGER_H__