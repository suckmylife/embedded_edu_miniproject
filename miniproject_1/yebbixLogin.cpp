#include "yebbixLogin.h"
YebbixLogin* YebbixLogin::instance = nullptr;

YebbixLogin::YebbixLogin()
{
    client_db = new ClientDB();
}
void YebbixLogin::show()
{
    string id_, psw_;
    cout << "\033[2J\033[1;1H";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                 YEBBIX : LOGIN              " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "   아이디 입력 : ";
    cin >> id_;
    cin.ignore(1000,'\n');
    cout << " 비밀번호 입력 : ";
    cin >> psw_;
    cin.ignore(1000,'\n');
    setID(id_);
    setPSW(psw_);
    bool isuser = confirm();
    if(isuser)
    {
        cin.clear();
        cout << "\033[2J\033[1;1H";
        cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "                 WELCOME YEBBIX              " << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
        cout << "            >  PRESS ENTER KEY <           " << endl;
        string key;
        getline(cin, key);
        if(cin){
            YebbixManager::getInstance()->setMenu(YebbixClientMain::getInstance());
            return;
        }
        else
            YebbixManager::getInstance()->destroyInstance();
    }
    else
    {
        cout << "\033[2J\033[1;1H";
        cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "            YOU'RE NOT YEBBIX MEMBER         " << endl;
        cout << "                 회원이 아닙니다              " << endl;
        cout << "             회원가입을 진행해 주세요          " << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl <<endl;
        cout << "            >  PRESS ENTER KEY <           " << endl;
        string key;
        getline(cin, key);
        if(cin)
            YebbixManager::getInstance()->setMenu(YebbixMain::getInstance());
        else
            YebbixManager::getInstance()->destroyInstance();
    }
       
}
void YebbixLogin::destroyInstance(){
    if (instance != nullptr) {
        delete instance; // 동적으로 할당된 인스턴스 해제
        instance = nullptr; // 포인터를 nullptr로 만들어 재사용 방지 (안전)
    }
}

YebbixLogin::~YebbixLogin()
{
    delete client_db;
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
