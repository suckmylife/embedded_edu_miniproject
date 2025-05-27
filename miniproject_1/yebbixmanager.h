#ifndef __YEBBIX_MANAGER_H__
#define __YEBBIX_MANAGER_H__

#include <map>
#include <vector>

#include "yebbixMain.h"

using namespace std;

class YebbixManager {
  public:
      YebbixManager();
      ~YebbixManager();
      //화면
      YebbixMain *Main;
      void CustomerMain(); //고객 메인
      void AdminMain(); // 관리자 메인

      //예외처리

      //트리거

  private:
      
};

#endif    // __YEBBIX_MANAGER_H__
