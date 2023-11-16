#include "../headers/student.hpp"

Student::Student(std::string firstName, std::string lastName, std::string schoolId){
    this->firstName=firstName;
    this->lastName=lastName;
    this->schoolId=schoolId;
    this->studentId=uuid::generate_uuid_v4();
}

std::string Student::getStudentId(){
    return this->studentId;
}

std::string Student::getLastName(){
    return this->lastName;
}

std::string Student::getFirstName(){
    return this->firstName;
}

std::string Student::getSchoolId(){
    return this->schoolId;
}

void Student::setStudentId(){
    this->studentId=uuid::generate_uuid_v4();
}

void Student::setFirstName(std::string firstName){
    this->firstName=firstName;
}

void Student::setLastName(std::string lastName){
    this->lastName=lastName;
}

void Student::setSchoolId(std::string schoolId){
    this->schoolId=schoolId;
}

std::ostream& operator<<(std::ostream& os, const Student& obj){
    return os << "|" << obj.studentId << "|" << obj.lastName << "|" << obj.firstName << "|" << obj.schoolId << std::endl;
}