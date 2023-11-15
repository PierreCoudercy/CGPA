#include "student.hpp"

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

std::ostream& operator<<(std::ostream& os, const Student& obj){
    return os << "|" << obj.studentId << "|" << obj.lastName << "|" << obj.firstName << "|" << obj.schoolId << std::endl;
}