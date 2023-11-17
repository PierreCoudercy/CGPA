#include "../headers/database.hpp"

Database::Database(std::string path){
    this->path=path;
    //std::ofstream {path};
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
    "FOREIGN KEY (schoolId) REFERENCES School (schoolId)"
    ");";
    this->request(studentTable);
    std::string gpaTable="CREATE TABLE IF NOT EXISTS GPA("
    "studentId TEXT,"
    "topic TEXT,"
    "grade TEXT,"
    "credit TEXT,"
    "PRIMARY KEY(studentId, topic),"
    "FOREIGN KEY (studentId) REFERENCES School (studentId)"
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
        std::cerr << "Impossible to execute the request on the student table " << sqlite3_errmsg(db) << std::endl;
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

std::string Database::request(std::string query, int expected_result){
    int rc;
    std::string result;
    sqlite3_stmt *request=0;
    rc=sqlite3_prepare_v2(this->db, query.c_str(), -1, &request, 0);
    if (rc==SQLITE_OK || request == 0){
        std::cerr << "Impossible to execute the select request on the student table" << std::endl;
        exit(1);
    }
    rc=sqlite3_step(request);
    if (rc==SQLITE_ROW){
        for(int i=0; i<expected_result;i++){
            result = result +" | "+reinterpret_cast<const char*>(sqlite3_column_text(request, 0));
        }
    }
    else if (rc==SQLITE_DONE){
        std::cerr << "No values where found for these parameters" << std::endl;
    }
    else{
        std::cerr << "An error has been encountered during the execution of the request" << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(request);
    sqlite3_close(db);
    return result;
}