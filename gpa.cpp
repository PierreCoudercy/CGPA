#include <iostream>
#include <map>

#include "gpa.hpp"

double calculate_GPA(std::string grade, double credit){
    double gradeValue = gradeToValue[grade];
    return (gradeValue*credit)/credit;
}