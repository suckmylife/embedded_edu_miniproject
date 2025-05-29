#ifndef __RECORD_DB_H__
#define __RECORD_DB_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>
#include <cstdlib>

using namespace std;

class RecordDB 
{
public:
    RecordDB();
    
    //기능 (페이지네이션 제외)
    void save(const string &client_ID);

    void getLastId(istream &file, char delimiter);
    void setLastId(string &id){lastId = id;};

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
    struct datas
    {
        vector<string> dbStat = {"OK","FAIL"};
        vector<string> session = {"8", "3", "10", "1", "6", "4", "9", "2", "7", "5"};
        vector<string> use_time = {
                                    "85:41:07",
                                    "29:13:58",
                                    "60:27:03",
                                    "17:09:44",
                                    "92:35:19",
                                    "05:01:21",
                                    "41:50:33",
                                    "77:18:02",
                                    "03:06:11",
                                    "51:24:59"
                                };
        vector<string> query_time = {"1234", "45", "3789", "500", "2890", "712", "4999", "200", "3051", "1547"};
        vector<string> step = {"0","1","2"};
    };
    

};

#endif //__RECORD_DB_H__