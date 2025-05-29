#include "yebbixShop.h"
YebbixShop* YebbixShop::instance = nullptr;
void YebbixShop::show()
{
    int col_num = 0;
    string stat;
    license_table = license_db->load();
    

    cout << "\033[2J\033[1;1H";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                        YEBBIX : LICENSE                      " << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl << " 주문번호 | 라이센스명 | 내용 " << endl;
    for (auto& r : license_table) {
        col_num = 0;
        for (vector<string>::iterator it = r.begin(); it != next(r.begin(),3); ++it){
            switch (col_num)
            {
            case 0:
                cout << setw(9)<< *it << " |";
                break;
            case 1:
                cout << setw(11)<< *it << " |";
                break;
            case 2:
                cout << " "<< *it;
                break;
            default:
                break;
            }
            
            col_num++;
        }
        cout << endl;
    }
    cout<< "원하시는 라이센스의 주문번호를 입력 하세요"<<endl;
    cout << " > ";
    
    cin >> order_num;
    cin.ignore(1000,'\n');
    if(cin){
       buy_view();
    }
    
}

void YebbixShop::buy_view()
{
    string card_num,pin_num;
    cout << "\033[2J\033[1;1H";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                        YEBBIX : BUY                          " << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout <<" 카드번호를 입력하세요 : ";
    cin >> card_num;
    cin.ignore(1000,'\n');
    cout <<" 카드 csv를 입력하세요 : ";
    cin >> pin_num;
    cin.ignore(1000,'\n');
    string userId = YebbixLogin::getInstance()->getID();
    // time_t : 시간을 초 단위로 저장하는 타입
    time_t now = time(nullptr);

    // 로컬 시간으로 변환
    tm* local_tm = localtime(&now);

    // 문자열로 출력
    asctime(local_tm);

    // 원하는 포맷으로 출력
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_tm);

    //csv 갱신 
    if((product_db->load(userId)).empty())
        product_db->save("new",buffer,"1.0.0");
    else
        product_db->update(userId,buffer);
    buy_db->save(userId,buffer,order_num,"today","someday",card_num,pin_num);

    cout << "\033[2J\033[1;1H";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                        구매되었습니다                         " << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "  > INPUT ANY KEY : ";
    string key;
    cin >> key;
    cin.ignore(1000,'\n');
    if(cin) {
        YebbixManager::getInstance()->setMenu(YebbixClientMain::getInstance());
        return;
    }
}

void YebbixShop::destroyInstance(){
    if (instance != nullptr) {
        delete instance; // 동적으로 할당된 인스턴스 해제
        instance = nullptr; // 포인터를 nullptr로 만들어 재사용 방지 (안전)
    }
}

vector<string> YebbixShop::getBuyInfo()
{
    string userId = YebbixLogin::getInstance()->getID();
    return buy_db->load(userId);
}

YebbixShop::~YebbixShop()
{
    delete buy_db;
}
