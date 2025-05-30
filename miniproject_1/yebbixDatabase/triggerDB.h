#ifndef __TRIGGER_DB_H__
#define __TRIGGER_DB_H__

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <istream>

using namespace std;

class TriggerDB 
{
public:
    TriggerDB();
    vector<vector<string>> load() ;
    void save(
             string client_ID = "", string client_psw = "", \
             string client_company = "", string client_name = "",\
             string client_team = "", string client_position = ""
            );
    vector<string> confirm(const string &client_ID);
    vector<string> update(const string &client_ID, const string &pd_time);
    void del(const string &client_ID);
    void getLastId(istream &file, char delimiter);
    void setLastId(string &id){lastId = id;};
    ~TriggerDB();
private:
    string lastId;
    string file_path = "yebbixDatabase/triggerDB.csv";
    vector<string> row;

};

#endif //__TRIGGER_DB_H__