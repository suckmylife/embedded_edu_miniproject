#include "yebbixLogin.h"

YebbixLogin::YebbixLogin(){
    
}

void YebbixLogin::show()
{
    string id_, psw_;
    cout << "\033[2J\033[1;1H";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                 YEBBIX : LOGIN              " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << " 아이디 입력 : ";
    cin >> id_;
    cout << " 비밀번호 입력 : ";
    cin >> psw_;

    setID(id_);
    setPSW(psw_);
}

YebbixLogin::~YebbixLogin()
{
}

int YebbixLogin::whoIs()
{

    
    return 0;
}
