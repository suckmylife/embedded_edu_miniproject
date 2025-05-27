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
    }
    cout << "하고는 있니"<<endl;
    setLastId(line);
}

void ClientDB::save(string client_ID, string client_psw, string client_company, string client_name, string client_team, string client_position)
{
    //last id 갖고 오기기
    ifstream file_;
    file_.open("clientDB.csv");
    getLastId(file_,'\n');
    file_.close();
    //저장 
    ofstream file("clientDB.csv",ios::app);
    if(!file.fail()) {
        size_t pos = lastId.find(",");  // ","의 위치를 찾음
        string firstValue = lastId.substr(0, pos);  // 0부터 "," 전까지 잘라옴
        cout << "last id : " << stoi(firstValue)<<endl;
        file << stoi(firstValue)+1 << "," << client_ID << "," << client_psw << "," <<\
                client_company << "," << client_name << "," <<\
                client_team << "," << client_position << "," << endl;
    }
    file.close();
}

void ClientDB::search(const string &client_ID)
{
}

void ClientDB::modify(const string &client_ID)
{
}

void ClientDB::del(const string &client_ID)
{
}



ClientDB::~ClientDB()
{
}
