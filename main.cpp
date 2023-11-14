#include <iostream>
#include <map>
#include "gpa.hpp"
#include "student.hpp"

int main(){
    std::cout << calculate_GPA("A", 2) << std::endl;
    std::cout << calculate_GPA("F", 8) << std::endl;
    std::cout << calculate_GPA("B-", 5) << std::endl;
}