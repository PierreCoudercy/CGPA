#include <iostream>
#include <map>

#include "../headers/gpa.hpp"
#include "../headers/student.hpp"
#include "../headers/school.hpp"
#include "../headers/menu.hpp"

//std::string DATABASE_PATH;

int main(){
    Database d1("tmp/gpa.sqlite3");
    // d1.create_tables();
    // School s1("Harvard");
    // s1.save(d1);
    // Student st1("John","Do",s1.getSchoolId());
    // st1.save(d1);
    // GPA g1(st1.getStudentId(),"ALGEBRA","A+",5);
    // g1.save(d1);
    // GPA g2(st1.getStudentId(),"HISTORY","C",2);
    // g2.save(d1);
    // GPA g3(st1.getStudentId(),"PHYSICS","B+",3.5);
    // g3.save(d1);
    menu::main_menu();
    return 0;
}