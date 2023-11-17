#ifndef DATABASE_H
#define DATABASE_H

#include "../sqlite3/sqlite3.h"
#include <iostream>
#include <fstream>
#include <string>

class Database{

    private:
        std::string path;
        sqlite3 *db;
    public:
        //CONSTRUCTOR
        Database(std::string path);
        //GETTER
        //SETTER
        //OPERATOR
        //METHODS
        void create_tables();
        void request(std::string query);
        std::string request(std::string query, int expected_result);
};

#endif