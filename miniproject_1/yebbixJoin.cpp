#include "yebbixJoin.h"
YebbixJoin* YebbixJoin::instance = nullptr;
void YebbixJoin::show()
{
    string id_,password_,company_,name_,team_,position_;
    cout << "\033[2J\033[1;1H";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                 YEBBIX : JOIN               " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

    cout << " 아이디 생성 : ";
    cin >> id_;

    cout << " 비밀번호 생성 : ";
    cin >> password_;

    cout << " 회사명 입력 : ";
    cin >> company_;

    cout << " 이름 입력 : ";
    cin >> name_;

    cout << " 소속 입력 : ";
    cin >> team_;

    cout << " 직급 입력 : ";
    cin >> position_;

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
    if(anw == '1') YebbixMain::getInstance()->show();
}

YebbixJoin::~YebbixJoin()
{
}
