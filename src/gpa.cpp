#include "../headers/gpa.hpp"

GPA::GPA(std::string studentId, std::string topic, std::string grade, double credit){
    this->studentId = studentId;
    this->topic = topic;
    this->grade = grade;
    this->credit = credit;
}

std::string GPA::getStudentId(){return this->studentId;}
std::string GPA::getTopic(){return this->topic;}
std::string GPA::getGrade(){return this->grade;}
double GPA::getCredit(){return this->credit;}

void GPA::setStudentId(std::string studenId){this->studentId=studentId;}
void GPA::setTopic(std::string topic){this->topic=topic;}
void GPA::setGrade(std::string grade){this->grade=grade;}
void GPA::setCredit(double credit){this->credit=credit;}

std::ostream& operator<<(std::ostream& os, const GPA& obj){
    return os << "|" << obj.studentId << "|" << obj.topic << "|" << obj.credit << "|" << obj.grade << "|" << std::endl;
}

void GPA::save(Database db){
    std::string values = "('"+this->studentId+"','"+this->topic+"','"+this->grade+"','"+std::to_string(this->credit)+"')";
    std::string query="INSERT INTO GPA (studentId, topic, grade, credit) VALUES "+values;
    db.request(query);
}

double GPA::calculate_GPA(){
    double gradeValue = this->gradeToValue.find(this->grade)->second;
    return (gradeValue*this->credit)/this->credit;
}
