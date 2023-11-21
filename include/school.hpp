#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>
#include <iostream>

#include "uuid.hpp"
#include "database.hpp"
class Database;

class School{

    private:
        std::string name;
        std::string schoolId;
    public:
        //CONSTRUCTOR
        School(std::string name);
        //GETTER
        std::string getSchoolId();
        std::string getName();
        //SETTER
        void setSchooldId();
        void setName(std::string name);
        //OPERATOR
        friend std::ostream& operator<<(std::ostream& os, const School& obj);
        //METHODS
        void save(Database db);
};

std::ostream& operator<<(std::ostream& os, const School& obj);

#endif