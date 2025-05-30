#include "yebbixmanager.h"
YebbixManager* YebbixManager::instance = nullptr;

YebbixManager::YebbixManager() : curMenu(nullptr), isRunning(true){}

YebbixManager::~YebbixManager()
{
    // 스택에 남아있는 메뉴들도 정리 (메모리 누수 방지)
    while (!menu.empty()) {
        menu.pop();
    }
    // currentMenu도 싱글턴이므로 delete하지 않음
    delete instance; // MenuManager 싱글턴 자신만 삭제
    instance = nullptr;
}

void YebbixManager::setMenu(YebbixUI *m)
{
    if(curMenu != m){
        curMenu = m;
        if (curMenu != nullptr ) { // 현재 메뉴가 있고, 새 메뉴와 다르면 스택에 푸시
            menu.push(m);
        }
    }
   
}

void YebbixManager::backMenu()
{
    if (!menu.empty()) {
        menu.pop();
        curMenu = menu.top();
        
    }else{
        quitMenu();
    }
}

void YebbixManager::currentMenu()
{
    if (curMenu)
        curMenu->show();
    else
        isRunning = false;
}

void YebbixManager::display()
{
    if (curMenu) {
        curMenu->show();
    } else {
        // 프로그램 시작 시 첫 메뉴 설정 또는 종료 시 메시지
        std::cout << "표시할 메뉴가 없습니다. 프로그램을 시작하거나 종료합니다." << std::endl;
        isRunning = false;
    }
}

void YebbixManager::destroyInstance()
{
   YebbixLogin::destroyInstance();
   YebbixMain::destroyInstance();
   YebbixJoin::destroyInstance();

   YebbixClientMain::destroyInstance();
   YebbixRecord::destroyInstance();
   YebbixWarnRecord::destroyInstance();
   YebbixCriticRecord::destroyInstance();
   YebbixShop::destroyInstance();
   YebbixTrigger::destroyInstance();
   exit(0);
}
