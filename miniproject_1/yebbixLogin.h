#ifndef __YEBBIX_LOGIN_H__
#define __YEBBIX_LOGIN_H__

#include <iostream>

#include "yebbixDatabase/clientDB.h"
#include "yebbixClient\yebbixClientMain.h"
#include "yebbixUI.h"
using namespace std;

class YebbixLogin : public YebbixUI
{
public:
    static YebbixLogin* getInstance(){
        if(!instance)
            instance = new YebbixLogin();
        return instance;
    }
    
    void show() override;
    bool isClient;

    vector<string> getClientInfo() const {return info;}

    void setClientInfo(vector<string> &row) { info = row; }
    string getID() const { return id; }
    string getPSW() const { return psw; }
    
    string setID(string &i)  { return id=i; }
    string setPSW(string &p)  { return psw=p; }

    ~YebbixLogin();
private:
    static YebbixLogin* instance;
    YebbixLogin(){client_db = new ClientDB();};
    vector<string> info;
    bool confirm();
    string id,psw;
    ClientDB *client_db;
    
};

#endif //__YEBBIX_LOGIN_H__