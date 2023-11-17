#include "../headers/school.hpp"

School::School(std::string name){
    this->name=name;
    this->schoolId=uuid::generate_uuid_v4();
}

std::string School::getSchoolId(){
    return this->schoolId;
}

std::string School::getName(){
    return this->name;
}

void School::setSchooldId(){
    this->schoolId=uuid::generate_uuid_v4();
}

void School::setName(std::string name){
    this->name=name;
}

std::ostream& operator<<(std::ostream& os, const School& obj){
    return os << "|" << obj.schoolId << "|" << obj.name << std::endl;
}

void School::save(Database db){
    std::string values = "('"+this->schoolId+"','"+this->name+"')";
    std::string query="INSERT INTO School (schoolId, name) VALUES "+values;
    db.request(query);
}