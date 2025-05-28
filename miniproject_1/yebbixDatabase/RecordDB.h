#ifndef __RECORD_DB_H__
#define __RECORD_DB_H__

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <istream>

using namespace std;

class RecordDB 
{
public:
    RecordDB();
    
    //기능 (페이지네이션 제외)
    vector<vector<string>> loadAll(const string &client_ID);
    vector<vector<string>> loadWarning(const string &client_ID);
    vector<vector<string>> loadCritical(const string &client_ID);
    ~RecordDB();
private:
    string lastId;
    string file_path = "yebbixDatabase/RecordDB.csv";
    enum stat{
        NORMAL,
        WARNING,
        CRITICAL
    };

};

#endif //__RECORD_DB_H__