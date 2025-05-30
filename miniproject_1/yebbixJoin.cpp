#include "yebbixJoin.h"
YebbixJoin* YebbixJoin::instance = nullptr;

YebbixJoin::YebbixJoin()
{
    client_db = new ClientDB();
    record_db = new RecordDB();
}

bool YebbixJoin::isHangul(wchar_t ch)
{
    return (ch >= 0xAC00 && ch <= 0xD7A3);
}

void YebbixJoin::show()
{
    string id_,password_,company_,name_,team_,position_;
    //bool isOk = true;
    cout << "\033[2J\033[1;1H";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                 YEBBIX : JOIN               " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

    //while(isOk)
    //cout << " 아이디 생성 : ";
    string id_s = " 아이디 생성 : ";
    id_ = validateAnswer( id_s,[this](const string &input_){
            bool isOk = false;
            // UTF-8 -> UTF-32로 변환 한글 검사
            wstring_convert<codecvt_utf8<wchar_t>> conv;
            wstring winput = conv.from_bytes(input_);

            for (wchar_t ch : winput) {
            if(input_.empty()){
                cout << "Hey Input your ID"<<endl;
                return false;
            }
            else{
                if(input_.length()>10)
                {
                    isOk = false;
                    cout << "HEY! INPUT YOUR ID! WHAT's WRONG WITH YOU"<<endl;
                }
                else if (isHangul(ch)) 
                    cout << "Don't use hangul ok? Retry";
                else
                    isOk = true;
                }
                return isOk;
            }
        });
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
