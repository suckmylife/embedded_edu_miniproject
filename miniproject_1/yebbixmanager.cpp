#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "yebbixmanager.h"

YebbixManager::YebbixManager()
{
    Main = new YebbixMain;
    Main->show();
}

YebbixManager::~YebbixManager()
{

}

void YebbixManager::CustomerMain()
{
}

void YebbixManager::AdminMain()
{
}