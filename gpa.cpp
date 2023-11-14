#include <iostream>
#include <map>

#include "gpa.hpp"

GPA::GPA(std::string studentId, std::string topic, std::string grade, double credit){
    studentId = studentId;
    topic = topic;
    grade = grade;
    credit = credit;
}

std::string GPA::getStudentId(){return this->studentId;}
std::string GPA::getTopic(){return this->topic;}
std::string GPA::getGrade(){return this->grade;}
double GPA::getCredit(){return this->credit;}

void GPA::setStudentId(std::string studenId){this->studentId=studentId;}
void GPA::setTopic(std::string topic){this->topic=topic;}
void GPA::setGrade(std::string grade){this->grade=grade;}
void GPA::setCredit(double credit){this->credit=credit;}

double GPA::calculate_GPA(){
    double gradeValue = this->gradeToValue.find(this->grade)->second;
    return (gradeValue*this->credit)/this->credit;
}