#include "productDB.h"

ProductDB::ProductDB()
{

}

vector<string> ProductDB::load(const string &client_ID)
{
    vector<string>         row;
    string                 line;
    ifstream               file;
    bool isbreak         = false;

    file.open(file_path);

    while(getline(file,line,'\n')){
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
    file.close();
    if(!isbreak)
        row.clear();
    
    return row;
}

void ProductDB::save(string clientID,string pd_stat, string pd_time, string pd_ver)
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
        file << to_string(id) <<","<< clientID<< "," << pd_stat << "," << pd_time << "," <<pd_ver;
    }
    file.close();
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
    else{
        *next(row.begin(),3) = pd_time;
        save(row[1],row[2],row[3],row[4]);
    }
        
    return row;
}

ProductDB::~ProductDB()
{
}

