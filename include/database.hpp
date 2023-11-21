#ifndef DATABASE_H
#define DATABASE_H

#include "../sqlite3/sqlite3.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "school.hpp"
#include "gpa.hpp"

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
        std::vector<std::vector<std::string>> request(std::string query, int expected_result);
        std::vector<std::vector<std::string>> selectSchoolByName(std::string schoolName);
        std::string selectSchoolIdByName(std::string schoolName);
        void deleteSchoolByName(std::string schoolName);
        std::vector<std::vector<std::string>> selectStudentByName(std::string firstName, std::string lastName);
        std::string selectStudentIdByName(std::string firstName, std::string lastName);
        void deleteStudentByName(std::string firstName, std::string lastName);
        std::vector<std::vector<std::string>> selectGPAByStudent(std::string studentId);
        void deleteGPAByStudentTopic(std::string studentId, std::string topic);
};

#endif