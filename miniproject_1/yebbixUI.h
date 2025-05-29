#ifndef __YEBBIX_UI_H__
#define __YEBBIX_UI_H__

#include <iostream>

using namespace std;
class YebbixUI{
    
public:
    virtual void show() = 0;
    virtual ~YebbixUI() = default;
};


#endif //__YEBBIX_UI_H__