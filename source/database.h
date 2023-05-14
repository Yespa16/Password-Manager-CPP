#include <string>
#include <iostream>
#include <vector>
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
void get_all_groups(User& user);

int add_password(Password&);
void get_all_passwords(User& user);


extern User USER;
extern PasswordGroup GROUP;
extern std::vector<PasswordGroup> GROUP_LIST;
extern std::vector<Password> PASSWORD_LIST;
