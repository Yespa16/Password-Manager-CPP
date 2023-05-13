#include "database.h"
#include <string>
#include <iostream>

User USER;


int get_user_callback(void* notUsed, int argc, char** argv, char** col_name);

void create_db(const char* dir, sqlite3* var) {
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open(dir, &DB);
    sqlite3_close(DB);
}


int create_user_table(sqlite3* db) {
    sqlite3* DB;
    std::string command = "CREATE TABLE IF NOT EXISTS user("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "username VARCHAR(100) unique, "
        "password VARCHAR(100), "
        "pin VARCHAR(4) );";


    try{
        int exit = 0;
        exit = sqlite3_open("database.db", &DB);
        std::cout << "Database opened \n";
        char* messageError;
        exit = sqlite3_exec(DB, command.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK){
            std::cout << "Couldn't create User table";
            std::cout << messageError << std::endl;
            sqlite3_free(messageError);
        }else{
            std::cout << "User table created successfully"<< std::endl;
        }
    }catch (const std::exception& e) {
        std::cout <<  e.what() << std::endl;
        return 1;
    }
    sqlite3_close(DB);
    return 0;
}


int create_password_group_table(sqlite3* db) {
    sqlite3* DB;
    std::string command = "CREATE TABLE IF NOT EXISTS group("
        "user_id INTEGER,"
        "name VARCHAR(100) UNIQUE,"
    "); ";

    try{
        int exit = sqlite3_open("database.db", &DB);
        char* messageError;
        exit = sqlite3_exec(DB, command.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK){
            std::cout << "Couldn't create Group table"<< std::endl;
            sqlite3_free(messageError);
        }else{
            std::cout << "Group table created successfully"<< std::endl;
        }
    }catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
    sqlite3_close(DB);
}


int create_password_table(sqlite3* db){
        sqlite3* DB;
        std::string command = "CREATE TABLE IF NOT EXISTS password("
                "user_id INTEGER,"
                "app VARCHAR(50),"
                "group_id INTEGER"
                "username VARCHAR(50),"
                "email VARCHAR(100),"
                "password VARCHAR(50),"
        ") ";

    try{
        int exit = sqlite3_open("database.db", &DB);
        char* messageError;
        exit = sqlite3_exec(DB, command.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK){
            std::cout << "Couldn't create Password table "<< std::endl;
            sqlite3_free(messageError);
        }else{
            std::cout << "Password table created successfully"<< std::endl;
        }
    }catch (const std::exception& e) {
        std::cout  << e.what() << std::endl;
        return 1;
    }
    return 0;
    sqlite3_close(DB);
}


int create_user(User& user) {
    sqlite3* DB;
    std::string username = user.get_username();
    std::string password = user.get_password();
    std::string pin = user.get_pin();
    std::string command = "INSERT INTO user (username, password, pin) VALUES('" + username + "', '" + password + "', '" + pin +"' );";
    try{
        int exit = 0;
        exit = sqlite3_open("database.db", &DB);
        char* messageError;
        exit = sqlite3_exec(DB, command.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK){
            std::cout << "Couldn't add the User "<< std::endl;
            sqlite3_free(messageError);
        }else{
            std::cout << "User was added successfully!"<< std::endl;
        }
    }catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    sqlite3_close(DB);
    return 0;
}



void get_user(std::string username) {
    sqlite3* DB;
    int exit = sqlite3_open("database.db", &DB);
    std::string command = "SELECT * FROM user WHERE username='" + username + "'";

    exit = sqlite3_exec(DB, command.c_str(), get_user_callback, NULL, NULL);
}



int get_user_callback(void* notUsed, int argc, char** argv, char** col_name){
    USER.set_id(atoi(argv[0]));
    USER.set_username(argv[1]);
    USER.set_password(argv[2]);
    USER.set_pin(argv[3]);

    return 0;
}

