#ifndef __YEBBIX_USER_MANAGER_H__
#define __YEBBIX_USER_MANAGER_H__

#include <iostream>
#include <string>
using namespace std;

class YebbixUserManager
{
public:
    static YebbixUserManager* getInstance(){
        if(!instance)
            instance = new YebbixUserManager();
        return instance;
    }
    string getLoginID(){return loginID;};
    void setLoginID(const string &id){loginID = id;};
    static void destroyInstance();
    
    ~YebbixUserManager();
private:
    static YebbixUserManager* instance;
    YebbixUserManager();
    string loginID;
};


#endif //__YEBBIX_USER_MANAGER_H__