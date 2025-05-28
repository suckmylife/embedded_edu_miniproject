#include "buyDB.h"

BuyDB::BuyDB()
{
}
vector<vector<string>> BuyDB::load(const string &clientID)
{
    vector<string> row;
    vector<vector<string>> table;
    ifstream               file;
    string line;
    file.open(file_path);
    while(getline(file,line,'\n')){
        stringstream ss(line);
        string cell;
        row.clear();
        while(getline(ss,cell,',')){
            row.push_back(cell);
        }
        table.push_back(row);
    }
    file.close();
    return table;
}
void BuyDB::save(
            string clientId,string buy_date, string buy_license , string buy_start ,\
            string buy_end, string buy_card ,string buy_pin)
{
    //last id 갖고 오기기
    ifstream file_;
    file_.open(file_path);
    getLastId(file_,'\n');
    file_.close();
    //저장 
    ofstream file(file_path,ios::app);
    if(!file.fail()) {
        int id = 0;
        size_t pos = lastId.find(",");  // ","의 위치를 찾음
        string firstValue = lastId.substr(0, pos);  // 0부터 "," 전까지 잘라옴
        id = stoi(firstValue)+1;
        file<<endl;
        file << to_string(id) << "," <<clientId<<","<< buy_date << "," << buy_license << "," <<\
                buy_start << "," << buy_end << "," <<\
                buy_card << "," << buy_pin;
    }
    file.close();
}

void BuyDB::getLastId(istream &file, char delimiter)
{
    string line;
    while(getline(file,line,delimiter)){
        stringstream ss(line);
        setLastId(line);
    }
}

BuyDB::~BuyDB()
{
}
