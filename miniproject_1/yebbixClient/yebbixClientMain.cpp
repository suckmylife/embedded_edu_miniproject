#include "yebbixClientMain.h"
YebbixClientMain* YebbixClientMain::instance = nullptr;

YebbixClientMain::YebbixClientMain(){
    buy_db = new BuyDB();
}

void YebbixClientMain::show()
{
    int ranks = WhatRank();
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
    string userId = YebbixLogin::getInstance()->getID();
    vector<string> info = buy_db->load(userId);//물어보자
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
    else{
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
        cin.ignore(1000,'\n');
        switch(ch) {
            case 1: 
                YebbixManager::getInstance()->setMenu(YebbixRecord::getInstance());
                isOk = false;
                break;
            case 2:
                YebbixManager::getInstance()->setMenu(YebbixShop::getInstance());
                isOk = false;
                break;
            case 3:
                isOk = false;
                YebbixManager::destroyInstance();
                break;
            default:
                cout<< "다시 입력하세요 : ";
                cin.clear();
                cin.ignore(1000,'\n');
                break;
        }
    }
    return;
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
        cin.ignore(1000,'\n');
        switch(ch) {
            case 1: 
                YebbixManager::getInstance()->setMenu(YebbixRecord::getInstance());
                isOk = false;
                break;
            case 2:
                YebbixManager::getInstance()->setMenu(YebbixWarnRecord::getInstance());
                isOk = false;
                break;
            case 3: 
                YebbixManager::getInstance()->setMenu(YebbixCriticRecord::getInstance());
                isOk = false;
                break;
            case 4:
                YebbixManager::getInstance()->setMenu(YebbixShop::getInstance());
                isOk = false;
                break;
            case 5:
                isOk = false;
                YebbixManager::destroyInstance();
                break;
            default:
                cout<< "다시 입력하세요 : ";
                cin.clear();
                cin.ignore(1000,'\n');
                break;
        }
    }
    return;
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
        cin.ignore(1000,'\n');
        switch(ch) {
            case 1: 
                YebbixManager::getInstance()->setMenu(YebbixShop::getInstance());
                isOk = false;
                break;
            case 2:
                isOk = false;
                YebbixManager::destroyInstance();
                break;
            default:
                cout<< "다시 입력하세요 : ";
                cin.clear();
                cin.ignore(1000,'\n');
                break;
        }
    }
    return;
}

void YebbixClientMain::destroyInstance(){
    if (instance != nullptr) {
        delete instance; // 동적으로 할당된 인스턴스 해제
        instance = nullptr; // 포인터를 nullptr로 만들어 재사용 방지 (안전)
    }
}

YebbixClientMain::~YebbixClientMain()
{
}
