#ifndef __TRIGGER_DB_H__
#define __TRIGGER_DB_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>

using namespace std;

class TriggerDB 
{
public:
    TriggerDB();
    vector<vector<string>> load(const string &client_ID) ;
    void add(string client_ID,string trigger_name = "", string trigger_cond = "", string trigger_step = "");
    void save(string trigger_ID = "",string client_ID="",string trigger_name = "", string trigger_cond = "", string trigger_step = "");
    vector<string> confirm(const string &client_ID);
    void update(const string &client_ID, const vector<string> &r);
    void del(const string &client_ID);
    void getLastId(istream &file, char delimiter);
    void setLastId(string &id){lastId = id;};
    ~TriggerDB();
private:
    string lastId;
    string file_path = "yebbixDatabase/triggerDB.csv";


};

#endif //__TRIGGER_DB_H__