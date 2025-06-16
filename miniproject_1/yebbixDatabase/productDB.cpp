#include "productDB.h"

ProductDB::ProductDB()
{

}

vector<string> ProductDB::load(const string &client_ID)
{
    vector<string>         row_;
    string                 line;
    ifstream               file;
    bool isbreak         = false;

    file.open(file_path);

    while(getline(file,line,'\n')){
        stringstream ss(line);
        string cell;
        row_.clear();
        
        while(getline(ss,cell,',')){
            row_.push_back(cell);
        }
        for (vector<string>::iterator it = row_.begin(); it != row_.end(); ++it) {
            if(*it == client_ID)
            {
                isbreak = true;
                break;
            }
        }
        if(isbreak)
            break;
    }
    file.close();
    if(!isbreak)
        row_.clear();
    
    return row_;
}

void ProductDB::save(string clientID,string pd_stat, string pd_ver)
{
    //last id 갖고 오기기
    ifstream file_;
    file_.open(file_path);
    getLastId(file_,'\n');
    file_.close();
    //저장 
    ofstream file(file_path,ios::app);
    int stat_num = rand() % 3;
    if(!file.fail()) {
        int id = 0;
        size_t pos = lastId.find(",");  // ","의 위치를 찾음
        string firstValue = lastId.substr(0, pos);  // 0부터 "," 전까지 잘라옴
        id = stoi(firstValue)+1;
        file<<endl;
        file << to_string(id) <<","<< clientID << ","<< pdStat[stat_num]<< "," << pd_stat << "," <<pd_ver;
    }
    file.close();
}

void ProductDB::del(const string &client_ID)
{
    vector<string>         row_;
    vector<vector<string>> table;
    string                 line;
    ifstream               file;

    //파일 읽어서 table에 담기
    file.open(file_path);
    while(getline(file,line,'\n')){
        stringstream ss(line);
        string       cell;

        row_.clear();

        while(getline(ss,cell,',')){
            row_.push_back(cell);
        }
        table.push_back(row_);
    }
    file.close();

    //삭제
    for(auto r = table.begin(); r != table.end();) 
    {
        auto& row_it = *r;
        bool found = find(row_it.begin(), row_it.end(), client_ID) != row_it.end();
        found ? (r = table.erase(r)) : ++r;
    }

    //삭제 후 csv 적용
    ofstream    file_;
    file_.open(file_path);
    for(auto r = table.begin(); r != table.end(); ++r){
        auto& row_it = *r;
        for(auto it = row_it.begin(); it != row_it.end(); ++it){
            (next(it) == row_it.end()) ? (file_ << *it) : (file_ << *it << ",");
        }
        if(next(r) != table.end()) file_<<endl;
    }
    file_.close();
    
}

void ProductDB::getLastId(istream &file, char delimiter)
{
    string line;
    while(getline(file,line,delimiter)){
        stringstream ss(line);
        setLastId(line);
    }
}

vector<string> ProductDB::update(const string &client_ID, const string &pd_time)
{
    vector<string> row;
    string line;
    ifstream file_;
    bool isbreak = false;

    file_.open(file_path);

    while(getline(file_,line,'\n')){
        stringstream ss(line);
        string cell;
        row.clear();
        
        while(getline(ss,cell,',')){
            row.push_back(cell);
        }
        for (vector<string>::iterator it = row.begin(); it != row.end(); ++it) {
            if(*it == client_ID)
            {
                isbreak = true;
                break;
            }
        }
        if(isbreak)
            break;
    }
    file_.close();

    //못찾은거니까 row를 비워라
    if(!isbreak)
        row.clear();
    else{//찾았으면 csv에서 원래꺼 지운다음에 갱신한 데이터 다시 넣어라
        *next(row.begin(),3) = pd_time;
        del(client_ID);
        save(row[1],row[3],row[4]);
    }
        
    return row;
}

ProductDB::~ProductDB()
{
}

