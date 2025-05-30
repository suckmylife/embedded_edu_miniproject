#ifndef __YEBBIX_JOIN_H__
#define __YEBBIX_JOIN_H__

#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

#include "yebbixDatabase/clientDB.h"
#include "yebbixDatabase/RecordDB.h"

#include "yebbixMain.h"
#include "yebbixUI.h"
#include "yebbixmanager.h"

using namespace std;

class YebbixJoin : public YebbixUI
{
public:
    static YebbixJoin* getInstance(){
        if(!instance)
            instance = new YebbixJoin();
        return instance;
    }
    void show();//화면 띄우기
    void join();//회원가입 데이터 ClientDB에 넘기기
    void Okmessage();
    ~YebbixJoin();

    string getID() const { return id; } //id 접근
    string getPSW() const { return password; } // password 접근

    void setID(const string &i)  {  id=i; }// id 값 할당
    void setPSW(const string &pass)  {  password=pass; }// password 값 할당
    void setCompany(const string &c)  {  company=c; }// company 값 할당
    void setName(const string &n)  {  name=n; }// name 값 할당
    void setTeam(const string &t)  {  team=t; }// team 값 할당
    void setPosition(const string &pos)  {  position=pos; }// position 값 할당
    static void destroyInstance();

private:
    YebbixJoin();
    static YebbixJoin *instance;
    string id,password,company,name,team,position;
    ClientDB *client_db;
    RecordDB * record_db;

    bool isHangul(wchar_t ch);
};

#endif //__YEBBIX_JOIN_H__