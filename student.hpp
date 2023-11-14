#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>

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
        //SETTER
        //OPERATOR
        //METHODS
};

#endif