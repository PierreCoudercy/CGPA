#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <sqlite3.h>

#include "uuid/uuid.hpp"

class Student{
    private:
        std::string studentId;
        std::string firstName;
        std::string lastName;
        std::string schoolId;
    public:
        //CONSTRUCTOR
        Student(std::string firstName, std::string lastName, std::string schoolId);
        //GETTER
        std::string getStudentId();
        std::string getLastName();
        std::string getFirstName();
        std::string getSchoolId();
        //SETTER
        //OPERATOR
        friend std::ostream& operator<<(std::ostream& os, const Student& obj);
        //METHODS
};

std::ostream& operator<<(std::ostream& os, const Student& obj);

#endif