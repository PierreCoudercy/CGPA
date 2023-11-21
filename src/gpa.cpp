#include "../include/gpa.hpp"

GPA::GPA(){}

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

double GPA::calculate_GPA(Database db, std::string studentId){
    double cgpa=0;
    double creditSum=0;
    std::string query = "SELECT grade, credit from GPA where studentId='"+studentId+"'";
    std::vector<std::vector<std::string>> result = db.request(query, 2);
    for (std::vector<std::string> line : result){
        cgpa=cgpa+(this->gradeToValue.find(line[0]))->second*(std::stod(line[1]));
        creditSum=creditSum+(std::stod(line[1]));
    }
    cgpa=cgpa/creditSum;
    return cgpa;
}
