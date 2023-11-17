#include "../headers/menu.hpp"

void menu::main_menu(){
    int user_cmd=-1;
    while(user_cmd != 5){
        std::cout << "Welcome to the CGPA calculator please choose one of the following options :" << std::endl;
        std::cout << "  - 1) To access the database" << std::endl;
        std::cout << "  - 2) To add/update a school" << std::endl;
        std::cout << "  - 3) To add/update a student" << std::endl;
        std::cout << "  - 4) To add/update a GPA" << std::endl;
        std::cout << "  - 5) Exit this command line" << std::endl;
        std::cout << "Type your command here : ";
        std::cin >> user_cmd;
        switch(user_cmd){
            case 1:
                std::cout << "You choose to access the database" << std::endl;
                break;
            case 2:
                std::cout << "You choose to add/update a school" << std::endl;
                break;
            case 3:
                std::cout << "You choose to add/update a student" << std::endl;
                break;
            case 4:
                std::cout << "You choose to add/update a GPA" << std::endl;
                break;
            case 5:
                std::cout << "Have a good day" << std::endl;
                break;
            default:
                std::cout << "The command type is not found" << std::endl;
                user_cmd=-1;
                break;
        }
    }
}