#include <iostream>
#include <map>
#include "gpa.hpp"
#include "student.hpp"

int main(){
    GPA g1("XXXX","ALGEBRA","A+",5);
    std::cout << g1 << g1.calculate_GPA() << std::endl;
    GPA g2("XXXX","HISTORY","C",2);
    std::cout << g2 << g2.calculate_GPA() << std::endl;
    GPA g3("XXXX","PHYSICS","B+",3.5);
    std::cout << g3 << g3.calculate_GPA() << std::endl;
}