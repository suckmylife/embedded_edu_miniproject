#ifndef __PRODUCT_DB_H__
#define __PRODUCT_DB_H__

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <istream>
#include <algorithm>

using namespace std;

class ProductDB 
{
public:
    ProductDB();
    
    //기능 (페이지네이션 제외)
    vector<string> load(const string &client_ID);
    void save(string clientID="",string pd_stat = "", string pd_ver = "" );
    void del(const string &client_ID);
    
    void getLastId(istream &file, char delimiter);
    void setLastId(string &id){lastId = id;};
    vector<string> update(const string &client_ID, const string &pd_time);
    void setTime(const string &time){cur_time = time;}
    string getTime(){return cur_time;}
    ~ProductDB();
private:
    string cur_time;
    string lastId;
    string file_path = "yebbixDatabase/productDB.csv";
    enum stat{
        NORMAL,
        WARNING,
        CRITICAL
    };
    vector<string> pdStat = {"Normal","Maintenance","Error"};

};

#endif //__PRODUCT_DB_H__