#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

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
        void execute_request(std::string request);
};

#endif