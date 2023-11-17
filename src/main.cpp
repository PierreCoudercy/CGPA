#include <iostream>
#include <map>
#include "../headers/gpa.hpp"
#include "../headers/student.hpp"
#include "../headers/school.hpp"

int main(){
    Database d1("tmp/gpa.sqlite3");
    d1.create_tables();
    School s1("Harvard");
    std::cout << s1 << std::endl;
    Student st1("John","Do",s1.getSchoolId());
    std::cout << st1 << std::endl;
    GPA g1(st1.getStudentId(),"ALGEBRA","A+",5);
    std::cout << g1 << g1.calculate_GPA() << std::endl;
    GPA g2(st1.getStudentId(),"HISTORY","C",2);
    std::cout << g2 << g2.calculate_GPA() << std::endl;
    GPA g3(st1.getStudentId(),"PHYSICS","B+",3.5);
    std::cout << g3 << g3.calculate_GPA() << std::endl;
}