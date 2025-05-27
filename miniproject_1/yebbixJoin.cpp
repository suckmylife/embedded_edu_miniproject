#include "yebbixJoin.h"

YebbixJoin::YebbixJoin()
{

}

void YebbixJoin::show()
{
    string id_,psw_,company_,name_,team_,position_;
    cout << "\033[2J\033[1;1H";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                 YEBBIX : JOIN               " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

    cout << " 아이디 생성 : ";
    cin >> id_;

    cout << " 비밀번호 생성 : ";
    cin >> psw_;

    cout << " 회사명 입력 : ";
    cin >> company_;

    cout << " 이름 입력 : ";
    cin >> name_;

    cout << " 소속 입력 : ";
    cin >> team_;

    cout << " 직급 입력 : ";
    cin >> position_;

    setID(id_);
    setPSW(psw_);
    setCompany(company_);
    setName(name_);
    setTeam(team_);
    setPosition(position_);
    cout << "join!! BEFORE";
    //join();
}

void YebbixJoin::join()
{
    cout << "join!!";
    ClientDB::save(id,psw,company,name,team,position);
}

YebbixJoin::~YebbixJoin()
{
}
