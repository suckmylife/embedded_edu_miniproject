#include "yebbixTrigger.h"

YebbixTrigger* YebbixTrigger::instance = nullptr;

YebbixTrigger::YebbixTrigger()
{
    trigger_db = new TriggerDB();
}

void YebbixTrigger::show()
{
    int col_num = 0;
    string stat;
    all_table = trigger_db->load();
    cout << "\033[2J\033[1;1H";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                        YEBBIX : TRIGGER                      " << endl;
    cout << "  [이전화면 : z ]                                              " <<endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl << "    트리거명   |        조건 내용        |        단계  "  << endl;
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

void YebbixTrigger::destroyInstance(){
    if (instance != nullptr) {
        delete instance; // 동적으로 할당된 인스턴스 해제
        instance = nullptr; // 포인터를 nullptr로 만들어 재사용 방지 (안전)
    }
}

YebbixTrigger::~YebbixTrigger()
{
    delete trigger_db;
}
