#ifndef __YEBBIX_UI_H__
#define __YEBBIX_UI_H__


#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <iostream>
#include "yebbixDatabase/clientDB.h"
#include "yebbixDatabase/RecordDB.h"
#include "yebbixDatabase/buyDB.h"
#include "yebbixDatabase/productDB.h"
#include "yebbixDatabase/LicenseDB.h"

#include "yebbixClient/yebbixClientMain.h"
#include "yebbixClient/yebbixWarnRecord.h"
#include "yebbixClient/yebbixRecord.h"
#include "yebbixClient/yebbixCriticRecord.h"
#include "yebbixClient/yebbixShop.h"


#include "yebbixLogin.h"
#include "yebbixJoin.h"
#include "yebbixMain.h"
#include "yebbixmanager.h"

using namespace std;

class YebbixUI{
    
public:
    virtual void show() = 0;
    virtual ~YebbixUI() = default;
    template<typename validate>
    string validateAnswer(string &prompt, validate& val);

};


#endif //__YEBBIX_UI_H__

