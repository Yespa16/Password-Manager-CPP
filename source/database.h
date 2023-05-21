#include <string>
#include <iostream>
#include <vector>
#include "../dependecies/sqlite/sqlite3.h"
#include "backend/password.h"


class DatabaseClass{
private:
    const char* dir;
    sqlite3* DB;


public:
    char* error_message;
    
    DatabaseClass();
    DatabaseClass(const char* _dir, sqlite3* db): dir(_dir), DB(db){}
    ~DatabaseClass();

    void create_db();
    int create_user_table();
    int create_password_table();

    int create_user(User &user);
    void get_user(const std::string username);

    int add_password(Password* p);
    void get_all_passwords(User &user);

};


class Data{
private:
    User USER;
    std::vector<Password*> PASSWORD_LIST;

    Data(){}
    static Data instance;

public:
    Data(const Data&) = delete;
    static User& GET_USER() {return Get().USER;}
    static std::vector<Password*>& GET_PASSWORD_LIST() {return Get().PASSWORD_LIST;}

    static Data& Get() {
        return instance;
    }
};