#ifndef __YEBBIX_JOIN_H__
#define __YEBBIX_JOIN_H__

#include <iostream>

#include "clientDB.h"

using namespace std;

class YebbixJoin : public ClientDB
{
public:
    YebbixJoin();
    void show();
    void join();
    ~YebbixJoin();
private:
    string id,psw,company,name,team,position;
    string getID() const { return id; }
    string getPSW() const { return psw; }

    void setID(const string &i)  {  id=i; }
    void setPSW(const string &pass)  {  psw=pass; }
    void setCompany(const string &c)  {  company=c; }
    void setName(const string &n)  {  name=n; }
    void setTeam(const string &t)  {  team=t; }
    void setPosition(const string &pos)  {  position=pos; }

};

#endif //__YEBBIX_JOIN_H__