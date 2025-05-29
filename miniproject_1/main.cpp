#include <iostream>
#include <fstream>
#include "yebbixmanager.h"
//test
using namespace std;
int main()
{

    // 1. 메뉴 관리자 인스턴스 획득
    YebbixManager* menuManager = YebbixManager::getInstance();

    // 2. 초기 메뉴 설정
    menuManager->setMenu(YebbixMain::getInstance());

    // 3. 메인 프로그램 루프
    while (menuManager->statMenu()) {
        menuManager->display(); // 현재 메뉴 화면을 보여줌
    }
    return 0;
}
