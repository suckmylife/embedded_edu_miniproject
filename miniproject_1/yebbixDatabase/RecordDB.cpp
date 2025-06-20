#include "RecordDB.h"

RecordDB::RecordDB()
{

}

void RecordDB::save(const string &client_ID)
{
    string db_stat,session_cnt,use_time , query_time, step;
    datas d;
    int stat_num =  rand() % 2;
    int num_10   = rand() % 10; // 0 ~ 9
    int step_num = rand() % 3;
    db_stat      = d.dbStat[stat_num];
    session_cnt  = d.session[num_10];
    use_time     = d.use_time[num_10];
    query_time   = d.query_time[num_10];
    step         = d.step[step_num];

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
        file << to_string(id) <<","<< client_ID<< "," << db_stat << "," \
        << session_cnt << "," <<use_time <<","<< query_time<< "," << step;
    }
    file.close();
}

void RecordDB::getLastId(istream &file, char delimiter)
{
    string line;
    while(getline(file,line,delimiter)){
        stringstream ss(line);
        setLastId(line);
    }
}


vector<vector<string>> RecordDB::loadAll(const string &client_ID)
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
vector<vector<string>> RecordDB::loadWarning(const string &client_ID)
{
    vector<vector<string>> table;
    string                 line;

    table = loadAll(client_ID);
    for(auto row = table.begin(); row!=table.end();){
        auto& row_it = *row;
        bool found = (row_it.back() == to_string(WARNING)) ? true : false;
        found ? ++row : (row = table.erase(row));
    }

    
    return table;
}
vector<vector<string>> RecordDB::loadCritical(const string &client_ID)
{
    vector<vector<string>> table;
    string                 line;

    table = loadAll(client_ID);
    for(auto row = table.begin(); row!=table.end();){
        auto& row_it = *row;
        bool found = (row_it.back() == to_string(CRITICAL)) ? true : false;
        found ? ++row : (row = table.erase(row));
    }
    return table;
}


RecordDB::~RecordDB()
{
}
