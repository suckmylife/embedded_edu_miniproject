#ifndef __BUY_DB_H__
#define __BUY_DB_H__

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <istream>

using namespace std;

class BuyDB 
{
public:
    BuyDB();
    //기능 (페이지네이션 제외)
    vector<string> load(const string &clientID);
    void save(
             string clientId = "",string buy_date = "", string buy_license = "", string buy_start = "",\
             string buy_end = "", string buy_card = "",string buy_pin = ""
            );
    void getLastId(istream &file, char delimiter);
    void setLastId(string &id){lastId = id;};
    ~BuyDB();
private:
    string lastId;
    string file_path = "yebbixDatabase/buyDB.csv";
    enum stat{
        NORMAL,
        WARNING,
        CRITICAL
    };

};

#endif //__BUY_DB_H__