#include "../include/database.hpp"

Database::Database(std::string path){
    this->path=path;
}

void Database::create_tables(){
    std::string schoolTable="CREATE TABLE IF NOT EXISTS School("
    "schoolId TEXT PRIMARY KEY,"
    "name TEXT"
    ");";
    this->request(schoolTable);
    std::string studentTable="CREATE TABLE IF NOT EXISTS Student("
    "studentId TEXT PRIMARY KEY,"
    "firstName TEXT,"
    "lastName TEXT,"
    "schoolId TEXT,"
    "FOREIGN KEY (schoolId) REFERENCES School (schoolId) ON DELETE CASCADE"
    ");";
    this->request(studentTable);
    std::string gpaTable="CREATE TABLE IF NOT EXISTS GPA("
    "studentId TEXT,"
    "topic TEXT,"
    "grade TEXT,"
    "credit TEXT,"
    "PRIMARY KEY(studentId, topic),"
    "FOREIGN KEY (studentId) REFERENCES School (studentId) ON DELETE CASCADE"
    ");";
    this->request(gpaTable);
}

void Database::request(std::string query){
    int rc;
    rc = sqlite3_open (this->path.c_str(),  &this->db);
    if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }
    sqlite3_stmt *request=0;
    rc=sqlite3_prepare_v2(this->db, query.c_str(), -1, &request, 0);
    if (rc != SQLITE_OK || request == 0){
        std::cerr << "Impossible to execute the request on the table " << sqlite3_errmsg(db) << std::endl;
        exit(1);
    }
    rc=sqlite3_step(request);
    if (rc==SQLITE_DONE){
        std::cerr << "No values where found for these parameters" << std::endl;
    }
    else{
        std::cerr << "An error has been encountered during the execution of the request" << sqlite3_errmsg(db) << std::endl;
        exit(1);
    }

    sqlite3_finalize(request);
    sqlite3_close(db);
}

std::vector<std::vector<std::string>> Database::request(std::string query, int expected_result){
    int rc;
    std::vector<std::vector<std::string>> result;
    rc = sqlite3_open (this->path.c_str(),  &this->db);
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }
    sqlite3_stmt *request=0;
    rc=sqlite3_prepare_v2(this->db, query.c_str(), -1, &request, 0);
    if (rc!=SQLITE_OK || request == 0){
        std::cerr << "Impossible to execute the select request on the table " << sqlite3_errmsg(db) << std::endl;
        exit(1);
    }
    do{
        std::vector<std::string> tmp;
        rc=sqlite3_step(request);
        if (rc==SQLITE_ROW){
        for(int i=0; i<expected_result;i++){
            tmp.push_back(reinterpret_cast<const char*>(sqlite3_column_text(request, i)));
        }
        result.push_back(tmp);
    }
    }
    while(rc == SQLITE_ROW);
    if (rc==SQLITE_DONE){
        std::cerr << "No values where found for these parameters" << std::endl;
    }
    else{
        std::cerr << "An error has been encountered during the execution of the request" << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(request);
    sqlite3_close(db);
    return result;
}

std::vector<std::vector<std::string>> Database::selectSchoolByName(std::string schoolName){
    std::string query="SELECT * FROM School WHERE name='"+schoolName+"'";
    std::vector<std::vector<std::string>> result=this->request(query, 2);
    return result;
}

std::string Database::selectSchoolIdByName(std::string schoolName){
    std::string query="SELECT schoolId FROM School WHERE name='"+schoolName+"'";
    std::vector<std::vector<std::string>> result=this->request(query, 1);
    return result[0][0];
}

void Database::deleteSchoolByName(std::string schoolName){
    std::string query="DELETE FROM School WHERE name='"+schoolName+"'";
    this->request(query);
}

std::vector<std::vector<std::string>> Database::selectStudentByName(std::string firstName, std::string lastName){
    std::string query="SELECT * FROM Student WHERE firstName='"+firstName+"' AND lastName='"+lastName+"'";
    std::vector<std::vector<std::string>> result=this->request(query, 4);
    return result;
}

std::string Database::selectStudentIdByName(std::string firstName, std::string lastName){
    std::string query="SELECT * FROM Student WHERE firstName='"+firstName+"' AND lastName='"+lastName+"'";
    std::vector<std::vector<std::string>> result=this->request(query, 4);
    return result[0][0];
}

void Database::deleteStudentByName(std::string firstName, std::string lastName){
    std::string query="DELETE FROM Student WHERE firstName='"+firstName+"' AND lastName='"+lastName+"'";
    this->request(query);
}

std::vector<std::vector<std::string>> Database::selectGPAByStudent(std::string studentId){
    std::string query="SELECT * FROM GPA WHERE studentId='"+studentId+"'";
    std::vector<std::vector<std::string>> result=this->request(query, 4);
    return result;
}

void Database::deleteGPAByStudentTopic(std::string studentId, std::string topic){
    std::string query="DELETE FROM GPA WHERE studenId='"+studentId+"' AND topic='"+topic+"'";
    this->request(query);
}