#include "yebbixMain.h"
YebbixMain* YebbixMain::instance = nullptr;
void YebbixMain::show()
{
    int ch;
    bool isOk = true;
    cout << "\033[2J\033[1;1H";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                   YEBBIX                    " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "  1. 로그인                                  " << endl;
    cout << "  2. 회원가입                                " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << " 선택 : ";
    
    while(isOk){
        cin >> ch;
        cin.ignore(1000,'\n');
        switch(ch) {
            case 1: 
                YebbixManager::getInstance()->setMenu(YebbixLogin::getInstance());
                isOk = false;
                break;
            case 2:
                YebbixManager::getInstance()->setMenu(YebbixJoin::getInstance());
                isOk = false;
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

void YebbixMain::destroyInstance(){
    if (instance != nullptr) {
        delete instance; // 동적으로 할당된 인스턴스 해제
        instance = nullptr; // 포인터를 nullptr로 만들어 재사용 방지 (안전)
    }
}

YebbixMain::~YebbixMain()
{
}
