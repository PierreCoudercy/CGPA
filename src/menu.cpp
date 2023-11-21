#include "../include/menu.hpp"

void menu::main_menu(Database * db){
    int user_cmd=-1;
    while(user_cmd != 5){
        std::cout << "Welcome to the CGPA calculator please choose one of the following options :" << std::endl;
        std::cout << "  - 1) To access the database" << std::endl;
        std::cout << "  - 2) To add a object" << std::endl;
        std::cout << "  - 3) To delete an object" << std::endl;
        std::cout << "  - 4) To calculate the CGPA of a student" << std::endl;
        std::cout << "  - 5) Exit this command line" << std::endl;
        std::cout << "Type your command here : ";
        std::cin >> user_cmd;
        switch(user_cmd){
            case 1:
                show_menu(db);
                break;
            case 2:
                std::cout << "You choose to add an object" << std::endl;
                add_menu(db);
                break;
            case 3:
                std::cout << "You choose to delete an object" << std::endl;
                delete_menu(db);
                break;
            case 4:
                std::cout << "You choose to calculate the CGPA" << std::endl;
                calculate_cgpa(db);
                break;
            case 5:
                std::cout << "Have a good day" << std::endl;
                break;
            default:
                std::cout << "The command typed is not found" << std::endl;
                user_cmd=-1;
                break;
        }
    }
}

void menu::show_menu(Database * db){
    int user_cmd=-1;
    while(user_cmd!=4){
        std::cout << "The following commands are available:" << std::endl;
        std::cout << " - 1) Schools" << std::endl;
        std::cout << " - 2) Students" << std::endl;
        std::cout << " - 3) GPA per student" << std::endl;
        std::cout << " - 4) To return to the previous menu" << std::endl;
        std::cout << "Type your command here : ";
        std::cin >> user_cmd;
        std::string firstName;
        std::string lastName;
        std::string schoolName;
        std::string studentId;
        std::vector<std::vector<std::string>> result;
        switch(user_cmd){
            case 1:
                std::cout << "Please type a school name :" << std::endl;
                std::cin >> schoolName;
                result=db->selectSchoolByName(schoolName);
                break;
            case 2:
                std::cout << "Please type a student first name :" << std::endl;
                std::cin >> firstName;
                std::cout << "Please type a student last name :" << std::endl;
                std::cin >> lastName;
                result=db->selectStudentByName(firstName, lastName);
                break;
            case 3:
                std::cout << "Please type a student first name :" << std::endl;
                std::cin >> firstName;
                std::cout << "Please type a student last name :" << std::endl;
                std::cin >> lastName;
                studentId = db->selectStudentIdByName(firstName, lastName);
                result=db->selectGPAByStudent(studentId);
                break;
            case 4:
                break;
            default:
                std::cout << "The command typed is not found" << std::endl;
                user_cmd=-1;
                break;
        }
        for (std::vector<std::string> line : result){
            std::string display="|";
            for (std::string value : line){
                display = display+" "+value+" |";
            }
            std::cout << display << std::endl;
        }
    }
}

void menu::add_menu(Database * db){
    int user_cmd=-1;
    while(user_cmd != 4){
        std::cout << "Welcome to the CGPA calculator please choose one of the following options :" << std::endl;
        std::cout << "  - 1) To add a School" << std::endl;
        std::cout << "  - 2) To add a Student" << std::endl;
        std::cout << "  - 3) To add a GPA" << std::endl;
        std::cout << "  - 4) To return to the previous menu" << std::endl;
        std::cout << "Type your command here : ";
        std::cin >> user_cmd;
        switch(user_cmd){
            case 1:
                std::cout << "You choose to add an object" << std::endl;
                add_school_menu(db);
                break;
            case 2:
                std::cout << "You choose to delete an object" << std::endl;
                add_student_menu(db);
                break;
            case 3:
                std::cout << "You choose to add a GPA" << std::endl;
                add_gpa_menu(db);
                break;
            case 4:
                break;
            default:
                std::cout << "The command typed is not found" << std::endl;
                user_cmd=-1;
                break;
        }
    }
}

void menu::add_school_menu(Database * db){
    std::string school_name;
    std::cout << "Please indicates the name of the school" << std::endl;
    std::cin >> school_name;
    School s(school_name);
    s.save(*db);
}

void menu::add_student_menu(Database * db){
    std::string firstName;
    std::string lastName;
    std::string schoolName;
    std::string schoolId;
    std::cout << "Please type a student first name :" << std::endl;
    std::cin >> firstName;
    std::cout << "Please type a student last name :" << std::endl;
    std::cin >> lastName;
    std::cout << "Please type a school name :" << std::endl;
    std::cin >> schoolName;
    schoolId = db->selectSchoolIdByName(schoolName);
    Student s(firstName, lastName, schoolId);
    s.save(*db);
}

void menu::add_gpa_menu(Database * db){
    std::string firstName;
    std::string lastName;
    std::string studentId;
    std::cout << "Please type a student first name :" << std::endl;
    std::cin >> firstName;
    std::cout << "Please type a student last name :" << std::endl;
    std::cin >> lastName;
    studentId = db->selectStudentIdByName(firstName, lastName);
    std::string topic;
    std::string grade;
    double credit;
    std::cout << "Please type the topic to add : " << std::endl;
    std::cin >> topic;
    std::cout << "Please indicate the number of credit for that topic" << std::endl;
    std::cin >> credit;
    std::cout << "Please indicate the grade for that topic" << std::endl;
    std::cin >> grade;
    GPA g(studentId,topic, grade, credit);
    g.save(*db);
}

void menu::delete_menu(Database * db){
    int user_cmd=-1;
    while(user_cmd != 4){
        std::cout << "Welcome to the CGPA calculator please choose one of the following options :" << std::endl;
        std::cout << "  - 1) To delete a School" << std::endl;
        std::cout << "  - 2) To delete a Student" << std::endl;
        std::cout << "  - 3) To delete a GPA" << std::endl;
        std::cout << "  - 4) To return to the previous menu" << std::endl;
        std::cout << "Type your command here : ";
        std::cin >> user_cmd;
        switch(user_cmd){
            case 1:
                std::cout << "You choose to delete a school" << std::endl;
                delete_school_menu(db);
                break;
            case 2:
                std::cout << "You choose to delete an student" << std::endl;
                delete_student_menu(db);
                break;
            case 3:
                std::cout << "You choose to delete a GPA" << std::endl;
                delete_gpa_menu(db);
                break;
            case 4:
                break;
            default:
                std::cout << "The command typed is not found" << std::endl;
                user_cmd=-1;
                break;
        }
    }
}

void menu::delete_school_menu(Database * db){
    std::string school_name;
    std::cout << "Please indicates the name of the school" << std::endl;
    std::cin >> school_name;
    db->deleteSchoolByName(school_name);
}
void menu::delete_student_menu(Database * db){
    std::string firstName;
    std::string lastName;
    std::cout << "Please type a student first name :" << std::endl;
    std::cin >> firstName;
    std::cout << "Please type a student last name :" << std::endl;
    std::cin >> lastName;
    db->deleteStudentByName(firstName, lastName);
}
void menu::delete_gpa_menu(Database * db){
    std::string firstName;
    std::string lastName;
    std::string studentId;
    std::cout << "Please type a student first name :" << std::endl;
    std::cin >> firstName;
    std::cout << "Please type a student last name :" << std::endl;
    std::cin >> lastName;
    studentId = db->selectStudentIdByName(firstName, lastName);
    std::string topic;
    std::cout << "Please type the topic to add : " << std::endl;
    std::cin >> topic;
    db->deleteGPAByStudentTopic(studentId, topic);
}

void menu::calculate_cgpa(Database * db){
    std::string firstName;
    std::string lastName;
    std::string studentId;
    std::cout << "Please type a student first name :" << std::endl;
    std::cin >> firstName;
    std::cout << "Please type a student last name :" << std::endl;
    std::cin >> lastName;
    studentId = db->selectStudentIdByName(firstName, lastName);
    GPA g;
    double cgpa=g.calculate_GPA(*db, studentId);
    std::cout << firstName << " " << lastName << " CGPA : " << cgpa << std::endl;
}