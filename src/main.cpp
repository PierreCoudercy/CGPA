#include <iostream>
#include <map>

#include "../include/gpa.hpp"
#include "../include/student.hpp"
#include "../include/school.hpp"
#include "../include/menu.hpp"

std::string DATABASE_PATH = "tmp/gpa.sqlite3";

int main(){
    Database db(DATABASE_PATH);
    db.create_tables();
    menu::main_menu(&db);
    return 0;
}