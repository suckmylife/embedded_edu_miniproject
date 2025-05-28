#include "yebbixLogin.h"
YebbixLogin* YebbixLogin::instance = nullptr;
void YebbixLogin::show()
{
    string id_, psw_;
    cout << "\033[2J\033[1;1H";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                 YEBBIX : LOGIN              " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "   아이디 입력 : ";
    cin >> id_;
    cout << " 비밀번호 입력 : ";
    cin >> psw_;

    setID(id_);
    setPSW(psw_);
    bool isuser = confirm();
    if(isuser)
    {
        cout << "\033[2J\033[1;1H";
        cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "                 WELCOME YEBBIX              " << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
        cout << "  > INPUT ANY KEY : ";
        string key;
        cin >> key;
        if(cin)
            YebbixClientMain::getInstance()->show();
        
    }
    else
    {
        cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "                 회원이 아닙니다              " << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl <<endl;
        cout << "  > INPUT ANY KEY : ";
        string key;
        cin >> key;
        if(cin)
            show();
    }
       
}

YebbixLogin::~YebbixLogin()
{
}

bool YebbixLogin::confirm()
{
    vector<string> id_v = client_db->confirm(id);
    vector<string> psw_v = client_db->confirm(psw);

    if(!(id_v.empty()) && !(psw_v.empty()))
    {
        setClientInfo(id_v);
        return true;
    }
        
    else
        return false;
    
        
}
