#include "yebbixClientMain.h"
YebbixClientMain* YebbixClientMain::instance = nullptr;
void YebbixClientMain::show()
{
    bool ranks = WhatRank();
    cout << "\033[2J\033[1;1H";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                 YEBBIX : MAIN               " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    if( ranks == VIEWER){
        viewer_view();
    }
    else if(ranks == PRO){
        pro_view();
    }
    else{
        unrank_view();
    }
}

int YebbixClientMain::WhatRank()
{
    vector<string> info = YebbixShop::getInstance()->getBuyInfo();
    if(!info.empty())
    {
        int rank;
        try{
            rank = stoi(info[3]);
        }
        catch(const invalid_argument& e){
            rank = UNRANK;
        }
        
        if( rank == VIEWER)
            userRank = VIEWER;
        else if(rank == PRO)
            userRank = PRO;
        else
            userRank = UNRANK;
    }
    return userRank;
}

void YebbixClientMain::license_shop()
{
}

void YebbixClientMain::version_select()
{
}

void YebbixClientMain::viewer_view()
{
    int ch;
    bool isOk = true;
    cout << "  1. 전체기록 확인                            " << endl;
    cout << "  2. 라이센스 구매                            " << endl;
    cout << "  3. 종료                                     " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << " 선택 : ";
    
    while(isOk){
        cin >> ch;
        switch(ch) {
            case 1: 
                YebbixRecord::getInstance()->all_record_check();
                isOk = false;
                break;
            case 2:
                YebbixShop::getInstance()->show();
                isOk = false;
                break;
            case 3:
                isOk = false;
                exit(0);
                break;
            default:
                cout<< "다시 입력하세요 : ";
                cin.clear();
                cin.ignore(1000,'\n');
                break;
        }
    }
}

void YebbixClientMain::pro_view()
{
    int ch;
    bool isOk = true;
    cout << "  1. 전체기록 확인                            " << endl;
    cout << "  2. 경고이벤트 확인                          " << endl;
    cout << "  3. 위험이벤트 확인                          " << endl;
    cout << "  4. 라이센스 구매                            " << endl;
    cout << "  5. 종료                                     " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << " 선택 : ";
    
    while(isOk){
        cin >> ch;
        switch(ch) {
            case 1: 
                YebbixRecord::getInstance()->all_record_check();
                isOk = false;
                break;
            case 2:
                YebbixRecord::getInstance()->warning_record_check();
                isOk = false;
                break;
            case 3: 
                YebbixRecord::getInstance()->critical_record_check();
                isOk = false;
                break;
            case 4:
                YebbixShop::getInstance()->show();
                isOk = false;
                break;
            case 5:
                isOk = false;
                exit(0);
                break;
            default:
                cout<< "다시 입력하세요 : ";
                cin.clear();
                cin.ignore(1000,'\n');
                break;
        }
    }
}

void YebbixClientMain::unrank_view()
{
    int ch;
    bool isOk = true;
    
    cout << "  1. 라이센스 구매                            " << endl;
    cout << "  2. 종료                                     " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << " 선택 : ";
    
    while(isOk){
        cin >> ch;
        switch(ch) {
            case 1: 
                YebbixShop::getInstance()->show();
                isOk = false;
                break;
            case 2:
                isOk = false;
                exit(0);
                break;
            default:
                cout<< "다시 입력하세요 : ";
                cin.clear();
                cin.ignore(1000,'\n');
                break;
        }
    }
}

YebbixClientMain::~YebbixClientMain()
{
}
