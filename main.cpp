#include <iostream>
#include <map>
#include "gpa.hpp"
#include "student.hpp"

int main(){
    Student s1("John","Do","YYYY");
    std::cout << s1 << std::endl;
    GPA g1(s1.getStudentId(),"ALGEBRA","A+",5);
    std::cout << g1 << g1.calculate_GPA() << std::endl;
    GPA g2(s1.getStudentId(),"HISTORY","C",2);
    std::cout << g2 << g2.calculate_GPA() << std::endl;
    GPA g3(s1.getStudentId(),"PHYSICS","B+",3.5);
    std::cout << g3 << g3.calculate_GPA() << std::endl;
}