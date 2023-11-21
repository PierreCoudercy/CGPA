#ifndef GPA_H
#define GPA_H
#include <map>
#include <string>
#include <iostream>
#include <sqlite3.h>

#include "database.hpp"

class GPA{
private:
    std::string studentId;
    std::string topic;
    std::string grade;
    double credit;
    const std::map<std::string,double> gradeToValue = {
        {"A+",4.3},
        {"A",4.0},
        {"A-",3.7},
        {"B+",3.3},
        {"B",3.0},
        {"B-",2.7},
        {"C+",2.3},
        {"C",2.0},
        {"C-",1.7},
        {"D+",1.3},
        {"D",1.0},
        {"D-",0.7},
        {"F",0.0}
    };
public:
    //CONSTRUCTOR
    GPA();
    GPA(std::string studentId, std::string topic, std::string grade, double credit);
    //GETTER
    std::string getStudentId();
    std::string getTopic();
    std::string getGrade();
    double getCredit();
    //SETTER
    void setStudentId(std::string studentId);
    void setTopic(std::string topic);
    void setGrade(std::string grade);
    void setCredit(double credit);
    //OPERATOR
    friend std::ostream& operator<<(std::ostream& os, const GPA& obj);
    //METHODS
    void save(Database db);
    double calculate_GPA(Database db, std::string studentId);
};
std::ostream& operator<<(std::ostream& os, const GPA& obj);

#endif