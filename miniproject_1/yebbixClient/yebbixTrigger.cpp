#include "yebbixTrigger.h"

YebbixTrigger* YebbixTrigger::instance = nullptr;

YebbixTrigger::YebbixTrigger()
{
    trigger_db = new TriggerDB();
}

void YebbixTrigger::show()
{
    all_table = trigger_db->load(YebbixLogin::getInstance()->getID());
    show_table(all_table);
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "             수정, 삭제, 추가를 할 ID를 골라 주세요             " << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    string prompt = " ID 입력 >  ";
    string keys;
    keys = validateAnswer( prompt,[this](const string &input_){
        if(input_ == "z") return true;
        else if(!(trigger_db->confirm(input_).empty())) return true;
        return false;
    });
    if(keys == "z"){
        YebbixManager::getInstance()->backMenu();
        return;
    }
    else{
        setCrudRow(trigger_db->confirm(keys));
        setTriggerID(keys);
        crud_view();
        return;
    }
        
    return;
}
void YebbixTrigger::show_table(const vector<string> &table)
{
    int col_num = 0;
    cout << "\033[2J\033[1;1H";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                    YEBBIX : MODIFY MODE                      " << endl;
    cout << "  [이전화면 : z ]                                              " <<endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl << " ID  |  트리거명  |       조건 내용        |     단계  "  << endl;
    
    for (auto it = table.begin(); it != table.end();++it){
        switch (col_num)
        {
            case 0:
                cout << setw(6)<< *it << " |";
                break;
            case 2:
                cout << setw(8)<< *it << " |";
                break;
            case 3:
                cout << setw(20)<< *it << " |";
                break;
            case 4:
                cout << setw(11)<< *it;
                break;
            default:
                break;
        }
        col_num++;
    }
    cout << endl;
    
}

void YebbixTrigger::crud_view()
{
    if(!(getCrudRow().empty()))
        show_table(getCrudRow());
    else
        cout << " 화면 송출 불가 " << endl;
    cout << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                    Get your own Trigger                      " << endl;
    cout << "  [수정 : m ]    [삭제 : d ]    [추가 : a ]                    " <<endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    string prompt = " ID 입력 >  ";
    string keys;
    keys = validateAnswer( prompt,[this](const string &input_){
        if(input_ == "z" || input_ == "m" || input_ == "a" || input_ == "d"){
            return true;
        }
        return false;
    });
    if(keys == "z"){
        YebbixManager::getInstance()->backMenu();
        return;
    }
    else if(keys == "m"){
        update();
        return;
    }
    else if(keys == "a"){
        add();
        return;
    }
    else if(keys == "d"){
        del();
        return;
    }
}

void YebbixTrigger::show_table(const vector<vector<string>> &table)
{
    int col_num = 0;
    cout << "\033[2J\033[1;1H";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                        YEBBIX : TRIGGER                      " << endl;
    cout << "  [이전화면 : z ]                                              " <<endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl << " ID  |  트리거명  |       조건 내용        |     단계  "  << endl;
    for (auto& r : table) {
        col_num = 0;
        for (auto it = r.cbegin(); it != r.cend(); ++it){
            switch (col_num)
            {
            case 0:
                cout << setw(3)<< *it << " |";
                break;
            case 2:
                cout << setw(11)<< *it << " |";
                break;
            case 3:
                cout << setw(22)<< *it << " |";
                break;
            case 4:
                cout << setw(11)<< *it;
                break;
            default:
                break;
            }
            
            col_num++;
        }
        cout << endl;
    }
}

void YebbixTrigger::update()
{
    cout << " 수정 화면 입니다" <<endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "[ 단계 설정 ]"<<endl;
    cout << "[ 0 ] : NORMAL" <<endl;
    cout << "[ 1 ] : WARNING" <<endl;
    cout << "[ 2 ] : CRITICAL" <<endl;
    cout << "단계는 '0 ,1 ,2' 중 하나로 설정해주세요 " <<endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    string tr_name;
    string name_t = " 트리거명 : ";
    tr_name = validateAnswer( name_t,[this](const string &input_){
        if(input_.empty()){
            cout << endl;
            cout << "Hey Input Trigger Name"<<endl;
            return false;
        }
        return true;
    });
    setTriggerName(tr_name);
    string tr_cond;
    string cond_t = " 조건 내용 : ";
    tr_cond = validateAnswer( cond_t,[this](const string &input_){
        if(input_.empty()){
            cout << endl;
            cout << "Hey Input your Trigger condition"<<endl;
            return false;
        }
        else if(input_.length()>10){
            cout << endl;
            cout << "HEY 10 less"<<endl;
            return false;
        }
        return true;
    });
    setTriggerCond(tr_cond);
    string tr_step;
    int rank;
    string rank_s;
    string step_t =" 단계 설정 : ";
    tr_step = validateAnswer( step_t,[this](const string &input_){
        if(input_.empty()){
            cout << endl;
            cout << "Setting your Trigger step!"<<endl;
            return false;
        }
        return true;
    });
    setTriggerStep(tr_step);
    try{
        rank = stoi(tr_step);
    }
    catch(const invalid_argument& e){
        rank = NORMAL;
    }
    switch (rank)
    {
    case 0:
        rank_s = "NORMAL";
        break;
    case 1:
        rank_s = "WARNING";
        break;
    case 2:
        rank_s = "CRITICAL";
        break;
    default:
        break;
    }
    vector<string> update_data;
    update_data.push_back(getTriggerID());
    update_data.push_back(YebbixLogin::getInstance()->getID());
    update_data.push_back(getTriggerCond());
    update_data.push_back(getTriggerStep());
    setCrudRow(update_data);

    trigger_db->update(getTriggerID(),getCrudRow());
    show();
    return;
}

void YebbixTrigger::del()
{
    trigger_db->del(getTriggerID());
    show();
    return;
}

void YebbixTrigger::add()
{
    cout << " 추가 화면 입니다" <<endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "[ 단계 설정 ]"<<endl;
    cout << "[ 0 ] : NORMAL" <<endl;
    cout << "[ 1 ] : WARNING" <<endl;
    cout << "[ 2 ] : CRITICAL" <<endl;
    cout << "단계는 '0 ,1 ,2' 중 하나로 설정해주세요 " <<endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    string tr_name;
    string name_t = " 트리거명 : ";
    tr_name = validateAnswer( name_t,[this](const string &input_){
        if(input_.empty()){
            cout << endl;
            cout << "Hey Input Trigger Name"<<endl;
            return false;
        }
        return true;
    });
    string tr_cond;
    string cond_t = " 조건 내용 : ";
    tr_cond = validateAnswer( cond_t,[this](const string &input_){
        if(input_.empty()){
            cout << endl;
            cout << "Hey Input your Trigger condition"<<endl;
            return false;
        }
        else if(input_.length()>10){
            cout << endl;
            cout << "HEY 10 less"<<endl;
            return false;
        }
        return true;
    });
    string tr_step;
    int rank;
    string rank_s;
    string step_t =" 단계 설정 : ";
    tr_step = validateAnswer( step_t,[this](const string &input_){
        if(input_.empty()){
            cout << endl;
            cout << "Setting your Trigger step!"<<endl;
            return false;
        }
        return true;
    });
    try{
        rank = stoi(tr_step);
    }
    catch(const invalid_argument& e){
        rank = NORMAL;
    }
    switch (rank)
    {
    case 0:
        rank_s = "NORMAL";
        break;
    case 1:
        rank_s = "WARNING";
        break;
    case 2:
        rank_s = "CRITICAL";
        break;
    default:
        break;
    }
    trigger_db->save(tr_name,tr_cond,tr_step,"");
    show();
    return;
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
