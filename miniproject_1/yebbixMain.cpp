#include "yebbixMain.h"

YebbixMain::YebbixMain()
{
    
}

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
        switch(ch) {
            case 1: 
                login->show();
                isOk = false;
                break;
            case 2:
                join->show();
                isOk = false;
                break;
            default:
                cout<< "다시 입력하세요 : ";
                cin.clear();
                cin.ignore(1000,'\n');
                break;
        }
    }
}

YebbixMain::~YebbixMain()
{
}
