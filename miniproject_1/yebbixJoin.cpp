#include "yebbixJoin.h"
YebbixJoin* YebbixJoin::instance = nullptr;

YebbixJoin::YebbixJoin()
{
    client_db = new ClientDB();
    record_db = new RecordDB();
}
void YebbixJoin::show()
{
    string id_,password_,company_,name_,team_,position_;
    cout << "\033[2J\033[1;1H";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                 YEBBIX : JOIN               " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

    cout << " 아이디 생성 : ";
    cin >> id_;
    cin.ignore(1000,'\n');
    cout << " 비밀번호 생성 : ";
    cin >> password_;
    cin.ignore(1000,'\n');
    cout << " 회사명 입력 : ";
    cin >> company_;
    cin.ignore(1000,'\n');
    cout << " 이름 입력 : ";
    cin >> name_;
    cin.ignore(1000,'\n');
    cout << " 소속 입력 : ";
    cin >> team_;
    cin.ignore(1000,'\n');
    cout << " 직급 입력 : ";
    cin >> position_;
    cin.ignore(1000,'\n');
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
    char anw;
    cout << "\033[2J\033[1;1H";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "          YEBBIX : 회원가입 되었습니다        " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << " 확인하셨으면 1 을 눌러주세요 : ";
    cin >> anw;
    cin.ignore(1000,'\n');
    if(anw == '1') {
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
