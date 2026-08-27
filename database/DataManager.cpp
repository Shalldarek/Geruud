#include <iostream>
#include <fstream>
#include "DataManager.h"

DataManager::DataManager(const std::string& db_name) {
    dbName = db_name;
    db = nullptr; 

    int rc = sqlite3_open(dbName.c_str(), &db);
    
    if (rc != SQLITE_OK) {
        //std::cerr << "Error opening database: " << sqlite3_errmsg(db) << "\n";
    } else {
        //std::cout << "Database '" << dbName << "' opened successfully.\n";
    }
}

DataManager::~DataManager() {
    if (db) {
        sqlite3_close(db); 
        //std::cout << "Connection to database closed.\n";
    }
}

bool DataManager::createTable() {
    std::string sql = R"(
    CREATE TABLE IF NOT EXISTS main_village (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        num_of_yurts INTEGER NOT NULL DEFAULT 3,
        num_of_people INTEGER NOT NULL DEFAULT 7,
        num_of_warriors INTEGER NOT NULL DEFAULT 0,
        num_of_horses INTEGER NOT NULL DEFAULT 3,
        num_of_camp_fires INTEGER NOT NULL DEFAULT 1
    );

    INSERT OR IGNORE INTO main_village (id) VALUES (1);
    )";

    char* errMsg = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        //std::cerr << "Error creating table: " << errMsg << "\n";
        sqlite3_free(errMsg); 
        return false;
    }
    
    return true;
}

sqlite3* DataManager::getDb() {
    return db;
}

int DataManager::getNumberOfYurts() {
    std::string sql = "SELECT num_of_yurts FROM main_village WHERE id = 1;";
    sqlite3_stmt* stmt;
    int numOfYurts = 0;

    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        //std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << "\n";
        return -1; 
    }

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        numOfYurts = sqlite3_column_int(stmt, 0);
    } else {
        //std::cerr << "Error retrieving number of yurts: " << sqlite3_errmsg(db) << "\n";
        sqlite3_finalize(stmt);
        return -1; 
    }

    sqlite3_finalize(stmt);
    return numOfYurts;
}

int DataManager::getNumberOfPeople() {
    std::string sql = "SELECT num_of_people FROM main_village WHERE id = 1;";
    sqlite3_stmt* stmt;
    int numOfPeople = 0;

    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        //std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << "\n";
        return -1; 
    }

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        numOfPeople = sqlite3_column_int(stmt, 0);
    } else {
        //std::cerr << "Error retrieving number of people: " << sqlite3_errmsg(db) << "\n";
        sqlite3_finalize(stmt);
        return -1; 
    }

    sqlite3_finalize(stmt);
    return numOfPeople;
}

int DataManager::getNumberOfCampFires() {
    std::string sql = "SELECT num_of_camp_fires FROM main_village WHERE id = 1;";
    sqlite3_stmt* stmt;
    int numOfCampFires = 0;

    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        //std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << "\n";
        return -1; 
    }

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        numOfCampFires = sqlite3_column_int(stmt, 0);
    } else {
        //std::cerr << "Error retrieving number of campfires: " << sqlite3_errmsg(db) << "\n";
        sqlite3_finalize(stmt);
        return -1; 
    }

    sqlite3_finalize(stmt);
    return numOfCampFires;
}

int DataManager::addPeople(int numberOfPeople) {
    std::string sql = "UPDATE main_village SET num_of_people = num_of_people + ? WHERE id = 1;";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        //std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << "\n";
        return -1; 
    }

    sqlite3_bind_int(stmt, 1, numberOfPeople);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        //std::cerr << "Error updating number of people: " << sqlite3_errmsg(db) << "\n";
        sqlite3_finalize(stmt);
        return -1; 
    }

    sqlite3_finalize(stmt);
    return 0; 
}

int DataManager::addHorses(int numberOfHorses) {
    std::string sql = "UPDATE main_village SET num_of_horses = num_of_horses + ? WHERE id = 1;";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        //std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << "\n";
        return -1; 
    }

    sqlite3_bind_int(stmt, 1, numberOfHorses);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        //std::cerr << "Error updating number of horses: " << sqlite3_errmsg(db) << "\n";
        sqlite3_finalize(stmt);
        return -1; 
    }

    sqlite3_finalize(stmt);
    return 0; 
}