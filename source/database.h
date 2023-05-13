#include <string>
#include <iostream>
#include "../dependecies/sqlite/sqlite3.h"
#include "backend/password.h"

void create_db(const char* dir, sqlite3* var);
int create_user_table(sqlite3* db);
int create_password_group_table(sqlite3* db);
int create_password_table(sqlite3* db);

int create_user(User& user);
void get_user(std::string username);

int add_group(PasswordGroup&);
void get_group(std::string name);


extern User USER;
extern PasswordGroup GROUP;
