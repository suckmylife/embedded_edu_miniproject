#ifndef __YEBBIX_MANAGER_H__
#define __YEBBIX_MANAGER_H__

#include <stack>
#include <vector>
#include <cstdlib>

#include "yebbixJoin.h"
#include "yebbixLogin.h"
#include "yebbixMain.h"

#include "yebbixUI.h"

#include "yebbixClient/yebbixClientMain.h"
#include "yebbixClient/yebbixCriticRecord.h"
#include "yebbixClient/yebbixRecord.h"
#include "yebbixClient/yebbixWarnRecord.h"
#include "yebbixClient/yebbixShop.h"

using namespace std;

class YebbixManager {
public:
 static YebbixManager* getInstance() {
        if (!instance)
            instance = new YebbixManager();
        return instance;
    }
  static void destroyInstance();
  
  ~YebbixManager();
  //화면
  void setMenu(YebbixUI *m);
  void backMenu();
  void currentMenu();
  void display();

  //기능
  void quitMenu() { isRunning = false;};
  bool statMenu() const {return isRunning;}
  


private:
  static YebbixManager* instance;
  YebbixUI *curMenu;
  stack<YebbixUI*> menu;

  bool isRunning;
  YebbixManager();
};

#endif    // __YEBBIX_MANAGER_H__
