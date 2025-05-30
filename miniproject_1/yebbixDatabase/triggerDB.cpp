#include "triggerDB.h"

TriggerDB::TriggerDB()
{

}

void TriggerDB::update(const string &client_ID, const vector<string> &r)
{
    del(client_ID);
    save(r[0],r[1],r[2],r[3],r[4]);
}

vector<vector<string>> TriggerDB::load(const string &client_ID)
{
    vector<string>         row;
    vector<vector<string>> table;
    string                 line;
    ifstream               file;
    bool isbreak         = false;

    file.open(file_path);

    while(getline(file,line,'\n')){
        stringstream ss(line);
        string       cell;

        row.clear();

        while(getline(ss,cell,',')){
            row.push_back(cell);
        }
        for (vector<string>::iterator it = row.begin(); it != row.end(); ++it) {
            if(*it == client_ID)
                isbreak = true;
        }
        if(isbreak){
            table.push_back(row);
            isbreak = false;
        }
    }
    file.close();
    
    return table;
}

void TriggerDB::getLastId(istream &file, char delimiter)
{
    string line;
    while(getline(file,line,delimiter)){
        stringstream ss(line);
        setLastId(line);
    }
}
void TriggerDB::save(string trigger_ID,string client_ID,string trigger_name, string trigger_cond, string trigger_step)
{
    //last id 갖고 오기기
    ifstream file_;
    file_.open(file_path);
    getLastId(file_,'\n');
    file_.close();
    //저장 
    ofstream file(file_path,ios::app);
    if(!file.fail()) {
        file<<endl;
        file << trigger_ID << "," << client_ID<< "," << trigger_name << "," << trigger_cond << "," <<trigger_step;
    }
    file.close();
}

void TriggerDB::add(string client_ID,string trigger_name, string trigger_cond, string trigger_step)
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
        file << to_string(id) << ","  << client_ID<< ","<< trigger_name << "," << trigger_cond << "," <<trigger_step;
    }
    file.close();
}

vector<string> TriggerDB::confirm(const string &client_ID)
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
    return row;
}

void TriggerDB::del(const string &client_ID)
{
    vector<string>         row;
    vector<vector<string>> table;
    string                 line;
    ifstream               file;

    //파일 읽어서 table에 담기
    file.open(file_path);
    while(getline(file,line,'\n')){
        stringstream ss(line);
        string       cell;

        row.clear();

        while(getline(ss,cell,',')){
            row.push_back(cell);
        }
        table.push_back(row);
    }
    file.close();

    //삭제
    for(auto row = table.begin(); row != table.end();) 
    {
        auto& row_it = *row;
        bool found = find(row_it.begin(), row_it.end(), client_ID) != row_it.end();
        found ? (row = table.erase(row)) : ++row;
    }

    //삭제 후 csv 적용
    ofstream    file_;
    file_.open(file_path);
    for(auto row = table.begin(); row != table.end(); ++row){
        auto& row_it = *row;
        for(auto it = row_it.begin(); it != row_it.end(); ++it){
            (next(it) == row_it.end()) ? (file_ << *it) : (file_ << *it << ",");
        }
        if(next(row) != table.end()) file_<<endl;
    }
    file_.close();
}



TriggerDB::~TriggerDB()
{
}
