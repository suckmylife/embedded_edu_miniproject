#include "yebbixUI.h"
template <typename validate>
inline string YebbixUI::validateAnswer(string &prompt, validate &val)
{
    string value;
    bool isOk = true;

    // 이전 cin >> 로 남은 엔터키를 여기서 처리 (중요!)
    cin.ignore(1000, '\n');

    while (isOk) {
        cout << prompt;
        getline(cin, value); // 한 줄 전체 입력 받기

        if (cin.good()) {
            if (val(value)) {
                isOk = false;
            } else {
                cout << "Hey Retry. Format is wrong" << std::endl;
            }
        } else {
            cerr << "Turn off. you're computer is wrong" << std::endl;
            cin.clear();
            // getline은 보통 엔터키를 소비하지만, 오류 시에는 clear()만 필요
        }
    }
    return value;
}
