#ifndef __CLIENT_DB_H__
#define __CLIENT_DB_H__

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <istream>

using namespace std;

class ClientDB 
{
public:
    ClientDB();
    vector<vector<string>> load(istream &file, char delimiter) ;
    void save(
             string client_ID = "", string client_psw = "", \
             string client_company = "", string client_name = "",\
             string client_team = "", string client_position = ""
            );
    void search(const string &client_ID);
    void modify(const string &client_ID);
    void del(const string &client_ID);
    void getLastId(istream &file, char delimiter);
    void setLastId(string &id){lastId = id;};
    ~ClientDB();
private:
    string lastId;
    

};

#endif //__CLIENT_DB_H__