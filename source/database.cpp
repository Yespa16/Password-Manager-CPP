#include "database.h"
#include <string>
#include <iostream>


Data Data::instance;


int get_user_callback(void *notUsed, int argc, char **argv, char **col_name);
int get_group_callback(void *notUsed, int argc, char **argv, char **col_name);
int get_all_groups_callback(void *notUsed, int argc, char **argv, char **col_name);
int get_all_passwords_callback(void *notUsed, int argc, char **argv, char **col_name);



DatabaseClass::~DatabaseClass() {
    DB = nullptr;
}



void DatabaseClass::create_db()
{
    int exit = sqlite3_open(dir, &DB);
    sqlite3_close(DB);
}

int DatabaseClass::create_user_table()
{

    std::string command = "CREATE TABLE IF NOT EXISTS user("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "username VARCHAR(100) unique, "
                          "password VARCHAR(100), "
                          "pin VARCHAR(4) );";


    int exit = 0;
    exit = sqlite3_open(dir, &DB);
    exit = sqlite3_exec(DB, command.c_str(), NULL, 0, &error_message);

    if (exit != SQLITE_OK)
    {
        throw 1;
    }
    sqlite3_close(DB);
    return 0;
}

int DatabaseClass::create_password_table()
{
    std::string command = "CREATE TABLE IF NOT EXISTS password("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "user_id INTEGER,"
                          "app VARCHAR(50),"
                          "group_id INTEGER,"
                          "username VARCHAR(50),"
                          "email VARCHAR(100),"
                          "password VARCHAR(50),"
                          "phone_number VARCHAR(50),"
                          "reserve_email VARCHAR(50),"
                          "level VARCHAR(50),"
                          "description TEXT"
                          ") ";

    int exit = sqlite3_open("database.db", &DB);
    exit = sqlite3_exec(DB, command.c_str(), NULL, 0, &error_message);

    if (exit != SQLITE_OK){
        throw 1;
    }
    sqlite3_close(DB);
    return 0;
}

int DatabaseClass::create_user(User &user){

    std::string username = user.get_username();
    std::string password = user.get_password();
    std::string pin = user.get_pin();
    std::string command = "INSERT INTO user (username, password, pin) VALUES('" + username + "', '" + password + "', '" + pin + "' );";
    int exit = 0;
    exit = sqlite3_open(dir, &DB);
    exit = sqlite3_exec(DB, command.c_str(), NULL, 0, &error_message);

        if (exit != SQLITE_OK)
        {
            throw 1;
        }
    sqlite3_close(DB);
    return 0;
}

void DatabaseClass::get_user(const std::string username)
{
    int exit = sqlite3_open(dir, &DB);
    std::string command = "SELECT * FROM user WHERE username='" + username + "'";

    exit = sqlite3_exec(DB, command.c_str(), get_user_callback, NULL, NULL);
}

int DatabaseClass::add_password(Password* p)
{
    std::string command = p->add_sql();

    int exit = 0;
    exit = sqlite3_open("database.db", &DB);

    exit = sqlite3_exec(DB, command.c_str(), NULL, 0, &error_message);

        if (exit != SQLITE_OK){
            throw 1;
        }
    sqlite3_close(DB);
    return 0;
}

void DatabaseClass::get_all_passwords(User& user)
{
    std::string user_id = std::to_string(user.get_id());
    int exit = sqlite3_open("database.db", &DB);
    std::string command = "SELECT * FROM password WHERE user_id=" + user_id;

    exit = sqlite3_exec(DB, command.c_str(), get_all_passwords_callback, NULL, NULL);

    sqlite3_close(DB);
}

int get_user_callback(void *notUsed, int argc, char **argv, char **col_name)
{
    Data::GET_USER().set_id(atoi(argv[0]));
    Data::GET_USER().set_username(argv[1]);
    Data::GET_USER().set_password(argv[2]);
    Data::GET_USER().set_pin(argv[3]);
    return 0;
}

int get_all_passwords_callback(void *notUsed, int argc, char **argv, char **col_name)
{
    Password* p = new Password;
    p->set_id(atoi(argv[0]));
    p->set_user(&Data::GET_USER());
    p->set_app(argv[2]);
    p->set_password(argv[6]);
    Data::GET_PASSWORD_LIST().push_back(p);
    return 0;
}