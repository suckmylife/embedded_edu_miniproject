#include "yebbixShop.h"
YebbixShop* YebbixShop::instance = nullptr;
YebbixShop::YebbixShop()
{
    buy_db = new BuyDB();
    product_db = new ProductDB();
    license_db = new LicenseDB();
}
void YebbixShop::show()
{
    int col_num = 0;
    string stat;
    license_table = license_db->load();
    

    cout << "\033[2J\033[1;1H";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                        YEBBIX : LICENSE                      " << endl;
    cout << "  [이전화면 : z ]                                              " <<endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl << " 주문번호 | 라이센스명 |               내용               | 가격 " << endl;
    for (auto& r : license_table) {
        col_num = 0;
        for (vector<string>::iterator it = r.begin(); it != next(r.begin(),4); ++it){
            switch (col_num)
            {
            case 0:
                cout << setw(9)<< *it << " |";
                break;
            case 1:
                cout << setw(11)<< *it << " |";
                break;
            case 2:
                cout << setw(33)<< *it << " |";
                break;
            case 3:
                cout << " "<< *it;
                break;
            default:
                break;
            }
            
            col_num++;
        }
        cout << endl;
    }
    string prompt = "주문번호 입력 > ";
    string order_n;
    order_n = validateAnswer( prompt,[this](const string &input_){
        if(input_ == "0" || input_ == "1" || input_ == "z") {
            return true;
        }
        return false;
    });
    if(order_n == "z")
    {
        YebbixManager::getInstance()->backMenu();
        return;
    }
    else if(order_n == "0" || order_n == "1" )
    {
        setOrderNum(order_n);
        buy_view();
    }
    
}

void YebbixShop::buy_view()
{
    string card_num,pin_num;
    cout << "\033[2J\033[1;1H";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                        YEBBIX : BUY                          " << endl;
    cout << "  [이전화면 : z ]                                              " <<endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    string nums = " 카드번호를 입력하세요 > ";
    card_num = validateAnswer( nums,[this](const string &input_){
         if(input_.empty()){
            cout << endl;
            cout << "Hey Input your card number"<<endl;
            return false;
        }
        else if(input_.length() >10)
        {
            cout << endl;
            cout << "Card Number 10자리 넘지 않음?"<<endl;
            return false;
        }
        return true;
    });
    if(card_num == "z")
    {
        show();
        return;
    }
        
    

    string pins = " 카드 cvc를 입력하세요 > ";
    pin_num = validateAnswer( pins,[this](const string &input_){
         if(input_.empty()){
            cout << endl;
            cout << "Hey Input your card pin number"<<endl;
            return false;
        }
        return true;
    });
    if(pin_num == "z")
    {
        show();
        return;
    }
        
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
    buy_db->save(userId,buffer,getOrderNum(),"today","someday",card_num,pin_num);

    cout << "\033[2J\033[1;1H";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                        구매되었습니다                         " << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                     >  PRESS ENTER KEY <                     " << endl;
    string key;
    
    getline(cin, key);
    if(cin) {
        YebbixManager::getInstance()->setMenu(YebbixClientMain::getInstance());
        return;
    }
    else
        YebbixManager::getInstance()->destroyInstance();
    
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
