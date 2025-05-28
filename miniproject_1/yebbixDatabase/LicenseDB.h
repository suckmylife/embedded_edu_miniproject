#ifndef __LICENSE_DB_H__
#define __LICENSE_DB_H__

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <istream>

using namespace std;

class LicenseDB 
{
public:
    LicenseDB();
    //기능 (페이지네이션 제외)
    vector<vector<string>> load();

    ~LicenseDB();
private:
    string lastId;
    string file_path = "yebbixDatabase/LicenseDB.csv";
    enum stat{
        NORMAL,
        WARNING,
        CRITICAL
    };

};

#endif //__LICENSE_DB_H__