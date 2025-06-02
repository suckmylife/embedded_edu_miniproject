#ifndef __YEBBIX_LOGIN_H__
#define __YEBBIX_LOGIN_H__

#include <iostream>
#include <string>

#include "yebbixDatabase/clientDB.h"
#include "yebbixClient\yebbixClientMain.h"

#include "yebbixMain.h"
#include "yebbixmanager.h"
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
    
    void setID(string &i)  { id=i; }
    void setPSW(string &p)  { psw=p; }

    static void destroyInstance();
    ~YebbixLogin();
private:
    static YebbixLogin* instance;
    YebbixLogin();
    vector<string> info;
    bool confirm();
    string id,psw;
    ClientDB *client_db;
    
};

#endif //__YEBBIX_LOGIN_H__