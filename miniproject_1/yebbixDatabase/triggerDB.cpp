#include "triggerDB.h"

TriggerDB::TriggerDB()
{

}

vector<string> TriggerDB::update(const string &client_ID, const string &pd_time)
{
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
        save(row[1],row[2],row[3],row[4]);
    }
        
    return row;
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

void TriggerDB::save(string client_ID, string client_psw, string client_company, string client_name, string client_team, string client_position)
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
        file << to_string(id) << "," << client_ID << "," << client_psw << "," <<\
                client_company << "," << client_name << "," <<\
                client_team << "," << client_position;
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
}



TriggerDB::~TriggerDB()
{
}
