#ifndef __YEBBIX_MANAGER_H__
#define __YEBBIX_MANAGER_H__

#include <stack>
#include <vector>

#include "yebbixMain.h"
#include "yebbixUI.h"

using namespace std;

class YebbixManager {
public:
  YebbixManager();
  ~YebbixManager();
  //화면
  void CustomerMain(); //고객 메인
  void AdminMain(); // 관리자 메인
  void setMenu();
  void backMenu();

      //예외처리

      //트리거

private:
  stack<YebbixUI*> menu;
      
};

#endif    // __YEBBIX_MANAGER_H__
