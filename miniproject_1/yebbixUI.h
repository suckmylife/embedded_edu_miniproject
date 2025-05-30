#ifndef __YEBBIX_UI_H__
#define __YEBBIX_UI_H__

#include <iostream>

using namespace std;

class YebbixUI{
    
public:
    virtual void show() = 0;
    virtual ~YebbixUI() = default;
    template<typename validate>
    string validateAnswer(string &prompt, const validate& val){
        string value;
        bool isOk = true;
        while (isOk) {
            cout << prompt;
            cin >> value;
            cin.ignore(1000, '\n');// 이전 cin >> 로 남은 엔터키를 여기서 처리 (중요!)
            if (cin.good()) {
                if (val(value)) {
                    isOk = false;
                } else {
                    cout << "Hey Retry. Format is wrong" << endl;
                }
            } else {
                cerr << "Turn off. you're computer is wrong" << endl;
                cin.clear();
                // getline은 보통 엔터키를 소비하지만, 오류 시에는 clear()만 필요
            }
        }
        return value;
    };

};


#endif //__YEBBIX_UI_H__

