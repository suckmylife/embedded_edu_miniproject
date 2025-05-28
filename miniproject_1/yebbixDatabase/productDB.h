#ifndef __PRODUCT_DB_H__
#define __PRODUCT_DB_H__

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <istream>

using namespace std;

class ProductDB 
{
public:
    ProductDB();
    
    //기능 (페이지네이션 제외)
    vector<string> load(const string &client_ID);
    void save(string clientID="",string pd_stat = "", string pd_time = "", string pd_ver = "" );
    void getLastId(istream &file, char delimiter);
    void setLastId(string &id){lastId = id;};
    vector<string> update(const string &client_ID, const string &pd_time);
    ~ProductDB();
private:
    vector<string> row;
    string lastId;
    string file_path = "yebbixDatabase/productDB.csv";
    enum stat{
        NORMAL,
        WARNING,
        CRITICAL
    };

};

#endif //__PRODUCT_DB_H__