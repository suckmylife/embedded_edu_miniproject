#include "LicenseDB.h"

LicenseDB::LicenseDB()
{
}

vector<vector<string>> LicenseDB::load()
{
    vector<vector<string>> table;
    vector<string> row;
    string line;
    ifstream file;
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
    return table;
}

LicenseDB::~LicenseDB()
{
}
