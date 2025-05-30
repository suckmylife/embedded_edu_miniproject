#include "yebbixJoin.h"
YebbixJoin* YebbixJoin::instance = nullptr;

YebbixJoin::YebbixJoin()
{
    client_db = new ClientDB();
    record_db = new RecordDB();
}

bool YebbixJoin::isHangul(string text)
{
    for (unsigned char ch : text) {
        if (ch & 0x80) return true;  // 최상위 비트가 1이면 다바이트 문자(한글 등)
    }
    return false;
}

void YebbixJoin::show()
{
    string id_,password_,company_,name_,team_,position_;
    //bool isOk = true;
    cout << "\033[2J\033[1;1H";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                 YEBBIX : JOIN               " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    string id_s = " 아이디 생성 : ";
    id_ = validateAnswer( id_s,[this](const string &input_){
        if(input_.empty()){
            cout << endl;
            cout << "Hey Input your ID"<<endl;
            return false;
        }
        else if(input_.length()>10 || input_.length()<4){
            cout << endl;
            cout << "HEY 4 more 10 less"<<endl;
            return false;
        }
        else if (isHangul(input_)) 
        {
            cout << endl;
            cout << "Don't use hangul ok? Retry" << endl;
            return false;
        }
        else if(!((this->client_db->confirm(input_)).empty())){
            cout << endl;
            cout << "You already YEBBIX member. Please Login." << endl;
            return false;
        }
            
        return true;
    });
    string pass_ = " 비밀번호 생성 : ";
    password_ = validateAnswer( pass_,[this](const string &input_){
        if(input_.empty()){
            cout << endl;
            cout << "Hey Input your password"<<endl;
            return false;
        }
        else if(input_.length()>10 || input_.length()<5){
            cout << endl;
            cout << "HEY 5 more 10 less"<<endl;
            return false;
        }
        return true;
    });
    string com_ =" 회사명 입력 : ";
    company_ = validateAnswer( com_,[this](const string &input_){
        if(input_.empty()){
            cout << endl;
            cout << "We need your company name!"<<endl;
            return false;
        }
        return true;
    });
    string name_s =" 이름 입력 : ";
    name_ = validateAnswer( name_s,[this](const string &input_){
        if(input_.empty()){
            cout << endl;
            cout << "We need your name!"<<endl;
            return false;
        }
        return true;
    });
    string team_s =" 소속 입력 : ";
    team_ = validateAnswer( team_s,[this](const string &input_){
        if(input_.empty()){
            cout << endl;
            cout << "We need your team name!"<<endl;
            return false;
        }
        return true;
    });
    string pos =" 직급 입력 : ";
    position_ = validateAnswer( pos,[this](const string &input_){
        if(input_.empty()){
            cout << endl;
            cout << "What is your position? you don't know? INPUT NOBODY"<<endl;
            return false;
        }
        return true;
    });
    setID(id_);
    setPSW(password_);
    setCompany(company_);
    setName(name_);
    setTeam(team_);
    setPosition(position_);
    join();
}

void YebbixJoin::join()
{
    client_db->save(id,password,company,name,team,position);
    for(int i =0; i<10; i++)
        record_db->save(id);
    Okmessage();
}

void YebbixJoin::Okmessage()
{
    cout << "\033[2J\033[1;1H";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "          YEBBIX : 회원가입 되었습니다        " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    string prompt = " 확인하셨으면 1 을 눌러주세요 >  ";
    string anw;
    anw = validateAnswer( prompt,[this](const string &input_){
        if(input_ == "1") {
            return true;
        }
        return false;
    });
    if(anw == "1") {
        YebbixManager::getInstance()->setMenu(YebbixMain::getInstance());
        return;
    }
}

void YebbixJoin::destroyInstance(){
    if (instance != nullptr) {
        delete instance; // 동적으로 할당된 인스턴스 해제
        instance = nullptr; // 포인터를 nullptr로 만들어 재사용 방지 (안전)
    }
}

YebbixJoin::~YebbixJoin()
{
    delete client_db;
    delete record_db;
}
