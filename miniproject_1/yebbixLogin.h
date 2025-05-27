#ifndef __YEBBIX_LOGIN_H__
#define __YEBBIX_LOGIN_H__

#include <iostream>
#include "clientDB.h"

using namespace std;

class YebbixLogin : public ClientDB
{
public:
    YebbixLogin();
    void show();
    bool isClient;
    ~YebbixLogin();
private:
    int whoIs();
    string id,psw;
    string getID() const { return id; }
    string getPSW() const { return psw; }

    string setID(string &i)  { return id=i; }
    string setPSW(string &p)  { return psw=p; }


};

#endif //__YEBBIX_LOGIN_H__