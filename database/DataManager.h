#pragma once
#include <string>
#include <sqlite3.h>

class DataManager {
private:
    sqlite3* db;
    std::string dbName;

public:
    DataManager(const std::string& db_name);
    ~DataManager();

    bool createTable();
    sqlite3* getDb();
    int getNumberOfYurts();
    int getNumberOfPeople();
    int getNumberOfCampFires();
};