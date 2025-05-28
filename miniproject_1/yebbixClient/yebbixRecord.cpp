#include "yebbixRecord.h"
YebbixRecord* YebbixRecord::instance = nullptr;
void YebbixRecord::show()
{
    
}

void YebbixRecord::all_record_check()
{
    int col_num = 0;
    string stat;
    all_table = record_db->loadAll(YebbixLogin::getInstance()->getID());
    cout << "\033[2J\033[1;1H";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                        YEBBIX : ALL RECORD                         " << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl << " DB연결상태 | 세션수 |  가동시간  | 쿼리실행시간 |     단계 " << endl;
    for (auto& r : all_table) {
        col_num = 0;
        for (vector<string>::iterator it = next(r.begin(),2); it != r.end(); ++it){
            switch (col_num)
            {
            case 0:
                cout << setw(11)<< *it << " |";
                break;
            case 1:
                cout << setw(7)<< *it << " |";
                break;
            case 2:
                cout << setw(11)<< *it << " |";
                break;
            case 3:
                cout << setw(13)<< *it << " |";
                break;
            case 4:
                if(stoi(*it) == 1) stat = "WARNING";
                else if(stoi(*it) == 2) stat = "CRITICAL";
                else stat = "-";
                cout << setw(10)<< stat;
                break;
            default:
                break;
            }
            
            col_num++;
        }
        cout << endl;
    }
}

void YebbixRecord::warning_record_check()
{
    int col_num = 0;
    string stat;
    all_table = record_db->loadWarning(YebbixLogin::getInstance()->getID());
    cout << "\033[2J\033[1;1H";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                     YEBBIX : WARNING RECORD                  " << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl << " DB연결상태 | 세션수 |  가동시간  | 쿼리실행시간 |     단계 " << endl;
    for (auto& r : all_table) {
        col_num = 0;
        for (vector<string>::iterator it = next(r.begin(),2); it != r.end(); ++it){
            switch (col_num)
            {
            case 0:
                cout << setw(11)<< *it << " |";
                break;
            case 1:
                cout << setw(7)<< *it << " |";
                break;
            case 2:
                cout << setw(11)<< *it << " |";
                break;
            case 3:
                cout << setw(13)<< *it << " |";
                break;
            case 4:
                if(stoi(*it) == 1) stat = "WARNING";
                else if(stoi(*it) == 2) stat = "CRITICAL";
                else stat = "-";
                cout << setw(10)<< stat;
                break;
            default:
                break;
            }
            
            col_num++;
        }
        cout << endl;
    }
}

void YebbixRecord::critical_record_check()
{
    int col_num = 0;
    string stat;
    all_table = record_db->loadCritical(YebbixLogin::getInstance()->getID());
    cout << "\033[2J\033[1;1H";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                     YEBBIX : CRITICAL RECORD                 " << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl << " DB연결상태 | 세션수 |  가동시간  | 쿼리실행시간 |     단계 " << endl;
    for (auto& r : all_table) {
        col_num = 0;
        for (vector<string>::iterator it = next(r.begin(),2); it != r.end(); ++it){
            switch (col_num)
            {
            case 0:
                cout << setw(11)<< *it << " |";
                break;
            case 1:
                cout << setw(7)<< *it << " |";
                break;
            case 2:
                cout << setw(11)<< *it << " |";
                break;
            case 3:
                cout << setw(13)<< *it << " |";
                break;
            case 4:
                if(stoi(*it) == 1) stat = "WARNING";
                else if(stoi(*it) == 2) stat = "CRITICAL";
                else stat = "-";
                cout << setw(10)<< stat;
                break;
            default:
                break;
            }
            
            col_num++;
        }
        cout << endl;
    }
}

YebbixRecord::~YebbixRecord()
{
    
}
