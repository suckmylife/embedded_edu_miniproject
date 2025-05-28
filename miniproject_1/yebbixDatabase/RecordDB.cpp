#include "RecordDB.h"

RecordDB::RecordDB()
{

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
    vector<string>         row;
    vector<vector<string>> table;
    string                 line;
    ifstream               file;
    bool isId            = false;
    bool isW             = false;
    file.open(file_path);

    while(getline(file,line,'\n')){
        stringstream ss(line);
        string       cell;
        row.clear();

        while(getline(ss,cell,',')){
            row.push_back(cell);
        }
        for (vector<string>::iterator it = row.begin(); it != row.end(); ++it) 
            if( *it == client_ID) isId = true;
                
        if(stoi(row.back()) == WARNING) isW = true;
        if(isId && isW){
            table.push_back(row);
            isId = false;
            isW  = false;
        }
    }
    file.close();
    
    return table;
}
vector<vector<string>> RecordDB::loadCritical(const string &client_ID)
{
    vector<string>         row;
    vector<vector<string>> table;
    string                 line;
    ifstream               file;
    bool isId            = false;
    bool isC             = false;
    file.open(file_path);

    while(getline(file,line,'\n')){
        stringstream ss(line);
        string       cell;

        row.clear();

        while(getline(ss,cell,',')){
            row.push_back(cell);
        }
        for (vector<string>::iterator it = row.begin(); it != row.end(); ++it) {
            if(     *it  == client_ID)     isId = true;
            if(stoi(*it) == CRITICAL)       isC = true;
                
        }
        if(isId && isC){
            table.push_back(row);
            isId = false;
            isC  = false;
        }
    }
    file.close();
    
    return table;
}


RecordDB::~RecordDB()
{
}
