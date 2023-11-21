#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "../include/database.hpp"
#include "../include/school.hpp"
#include "../include/student.hpp"
#include "../include/gpa.hpp"

namespace menu{
    void main_menu(Database * db);
    void show_menu(Database * db);
    void add_menu(Database * db);
    void add_school_menu(Database * db);
    void add_student_menu(Database * db);
    void add_gpa_menu(Database * db);
    void delete_menu(Database * db);
    void delete_school_menu(Database * db);
    void delete_student_menu(Database * db);
    void delete_gpa_menu(Database * db);
    void calculate_cgpa(Database * db);
}

#endif