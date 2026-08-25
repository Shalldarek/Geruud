#include <iostream>
#include <fstream>
#include "DataManager.h"

DataManager::DataManager(const std::string& db_name) {
    dbName = db_name;
    db = nullptr; 

    int rc = sqlite3_open(dbName.c_str(), &db);
    
    if (rc != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << "\n";
    } else {
        std::cout << "Database '" << dbName << "' opened successfully.\n";
    }
}

DataManager::~DataManager() {
    if (db) {
        sqlite3_close(db); 
        std::cout << "Connection to database closed.\n";
    }
}

bool DataManager::createTable() {
    std::string sql = R"(

    CREATE TABLE IF NOT EXISTS main_village (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        num_of_yurts INTEGER NOT NULL,
        num_of_people INTEGER NOT NULL,
        num_of_warriors INTEGER NOT NULL,
        num_of_horses INTEGER NOT NULL,
        num_of_camp_fires INTEGER NOT NULL
    );

    
    )";

    char* errMsg = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "Error creating table: " << errMsg << "\n";
        sqlite3_free(errMsg); 
        return false;
    }
    
    return true;
}

sqlite3* DataManager::getDb() {
    return db;
}