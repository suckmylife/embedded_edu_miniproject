#include "yebbixCriticRecord.h"
YebbixCriticRecord* YebbixCriticRecord::instance = nullptr;
YebbixCriticRecord::YebbixCriticRecord()
{
    record_db = new RecordDB();
}
void YebbixCriticRecord::show()
{
    int col_num = 0;
    string stat;
    all_table = record_db->loadCritical(YebbixLogin::getInstance()->getID());
    cout << "\033[2J\033[1;1H";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                     YEBBIX : CRITICAL RECORD                 " << endl;
    cout << "  [이전화면 : z ]                                              " <<endl;
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
                stat = "CRITICAL";
                cout << setw(10)<< stat;
                break;
            default:
                break;
            }
            
            col_num++;
        }
        cout << endl;
    }
    string prompt = " 돌아가기 'z' 입력 >  ";
    string keys;
    keys = validateAnswer( prompt,[this](const string &input_){
        if(input_ == "z"){
            return true;
        }
        return false;
    });
    if(keys == "z"){
        YebbixManager::getInstance()->backMenu();
        return;
    }
        
}

void YebbixCriticRecord::destroyInstance(){
    if (instance != nullptr) {
        delete instance; // 동적으로 할당된 인스턴스 해제
        instance = nullptr; // 포인터를 nullptr로 만들어 재사용 방지 (안전)
    }
}

YebbixCriticRecord::~YebbixCriticRecord()
{
    delete record_db;
}
