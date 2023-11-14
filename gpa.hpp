#ifndef GPA_H
#define GPA_H
#include <map>
#include <string>

class GPA{

public:
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
    double calculate_GPA(std::string grade, double credit);

};

#endif