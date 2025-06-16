#include "yebbixUserManager.h"
YebbixUserManager* YebbixUserManager::instance = nullptr;

YebbixUserManager::YebbixUserManager()
{

}
void YebbixUserManager::destroyInstance()
{
    if (instance != nullptr) {
        delete instance; // 동적으로 할당된 인스턴스 해제
        instance = nullptr; // 포인터를 nullptr로 만들어 재사용 방지 (안전)
    }
}
YebbixUserManager::~YebbixUserManager()
{
    
}
