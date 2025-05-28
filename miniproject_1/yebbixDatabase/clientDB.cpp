#include "clientDB.h"

ClientDB::ClientDB()
{

}

vector<vector<string>> ClientDB::load(istream &file, char delimiter)
{
    vector<string> row;
    vector<vector<string>> table;
    string line;
    while(getline(file,line,'\n')){
        stringstream ss(line);
        string cell;
        row.clear();
        while(getline(ss,cell,',')){
            row.push_back(cell);
        }
        table.push_back(row);
    }
    return table;
}

void ClientDB::getLastId(istream &file, char delimiter)
{
    string line;
    while(getline(file,line,delimiter)){
        stringstream ss(line);
        setLastId(line);
    }
}

void ClientDB::save(string client_ID, string client_psw, string client_company, string client_name, string client_team, string client_position)
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

vector<string> ClientDB::confirm(const string &client_ID)
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

void ClientDB::del(const string &client_ID)
{
}



ClientDB::~ClientDB()
{
}
