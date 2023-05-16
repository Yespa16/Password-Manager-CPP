#include "database.h"
#include <string>
#include <iostream>

User USER;
PasswordGroup GROUP;
int GROUP_COUNT;
std::vector<PasswordGroup> GROUP_LIST;
std::vector<Password> PASSWORD_LIST;

int get_user_callback(void *notUsed, int argc, char **argv, char **col_name);

int get_group_callback(void *notUsed, int argc, char **argv, char **col_name);

int get_all_groups_callback(void *notUsed, int argc, char **argv, char **col_name);

int get_all_passwords_callback(void *notUsed, int argc, char **argv, char **col_name);

void create_db(const char *dir, sqlite3 *var)
{
    sqlite3 *DB;
    int exit = 0;
    exit = sqlite3_open(dir, &DB);
    sqlite3_close(DB);
}

int create_user_table(sqlite3 *db)
{
    sqlite3 *DB;
    std::string command = "CREATE TABLE IF NOT EXISTS user("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "username VARCHAR(100) unique, "
                          "password VARCHAR(100), "
                          "pin VARCHAR(4) );";

    try
    {
        int exit = 0;
        exit = sqlite3_open("database.db", &DB);
        std::cout << "Database opened \n";
        char *messageError;
        exit = sqlite3_exec(DB, command.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK)
        {
            std::cout << "Couldn't create User table";
            std::cout << messageError << std::endl;
            sqlite3_free(messageError);
        }
        else
        {
            std::cout << "User table created successfully" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    sqlite3_close(DB);
    return 0;
}

int create_password_group_table(sqlite3 *db)
{
    sqlite3 *DB;
    std::string command = "CREATE TABLE IF NOT EXISTS password_group("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "user_id INTEGER,"
                          "name VARCHAR(100)"
                          "); ";

    try
    {
        int exit = sqlite3_open("database.db", &DB);
        char *messageError;
        exit = sqlite3_exec(DB, command.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK)
        {
            std::cout << "Couldn't create Group table" << std::endl;
            std::cout << messageError;
            sqlite3_free(messageError);
        }
        else
        {
            std::cout << "Group table created successfully" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    sqlite3_close(DB);
    return 0;
}

int create_password_table(sqlite3 *db)
{
    sqlite3 *DB;
    std::string command = "CREATE TABLE IF NOT EXISTS password("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "user_id INTEGER,"
                          "app VARCHAR(50),"
                          "group_id INTEGER,"
                          "username VARCHAR(50),"
                          "email VARCHAR(100),"
                          "password VARCHAR(50)"
                          ") ";

    try
    {
        int exit = sqlite3_open("database.db", &DB);
        char *messageError;
        exit = sqlite3_exec(DB, command.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK)
        {
            std::cout << "Couldn't create Password table " << std::endl;
            sqlite3_free(messageError);
        }
        else
        {
            std::cout << "Password table created successfully" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    sqlite3_close(DB);
    return 0;
}

int create_user(User &user)
{
    sqlite3 *DB;
    std::string username = user.get_username();
    std::string password = user.get_password();
    std::string pin = user.get_pin();
    std::string command = "INSERT INTO user (username, password, pin) VALUES('" + username + "', '" + password + "', '" + pin + "' );";
    try
    {
        int exit = 0;
        exit = sqlite3_open("database.db", &DB);
        char *messageError;
        exit = sqlite3_exec(DB, command.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK)
        {
            std::cout << "Couldn't add the User " << std::endl;
            sqlite3_free(messageError);
        }
        else
        {
            std::cout << "User was added successfully!" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    sqlite3_close(DB);
    return 0;
}

void get_user(std::string username)
{
    sqlite3 *DB;
    int exit = sqlite3_open("database.db", &DB);
    std::string command = "SELECT * FROM user WHERE username='" + username + "'";

    exit = sqlite3_exec(DB, command.c_str(), get_user_callback, NULL, NULL);
}

int add_group(PasswordGroup &pg)
{
    sqlite3 *DB;
    std::string name = pg.get_name();
    std::string uid = std::to_string(USER.get_id());
    std::string command = "INSERT INTO password_group (user_id, name) VALUES(" + uid + ", '" + name + "')";

    try
    {
        int exit = sqlite3_open("database.db", &DB);
        char *messageError;
        exit = sqlite3_exec(DB, command.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK)
        {
            std::cout << "Couldn't add PasswordGroup  " << std::endl;
            sqlite3_free(messageError);
        }
        else
        {
            std::cout << "PasswordGroup added successfully" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    sqlite3_close(DB);
    return 0;
}

void get_group(std::string name)
{
    sqlite3 *DB;
    int exit = sqlite3_open("database.db", &DB);
    std::string command = "SELECT * FROM password_group WHERE name='" + name + "'";

    exit = sqlite3_exec(DB, command.c_str(), get_group_callback, NULL, NULL);

    sqlite3_close(DB);
}

void get_all_groups(User &user)
{
    sqlite3 *DB;
    std::string user_id = std::to_string(user.get_id());
    int exit = sqlite3_open("database.db", &DB);
    std::string command = "SELECT * FROM password_group WHERE user_id=" + user_id;
    exit = sqlite3_exec(DB, command.c_str(), get_all_groups_callback, NULL, NULL);

    sqlite3_close(DB);
}

int add_password(Password &p)
{
    sqlite3 *DB;
    std::string user_id = std::to_string(p.get_user()->get_id());
    std::string group_id = std::to_string(p.get_group()->get_id());
    std::string app = p.get_app();
    std::string email = p.get_email();
    std::string username = p.get_username();
    std::string password = p.get_password();
    std::string command = "INSERT INTO password (user_id, group_id, app, email, username, password) VALUES(" + user_id + ", " + group_id + ", '" + app + "', '" + email + "', '" + username + "', '" + password + " ');";

    try
    {
        int exit = 0;
        exit = sqlite3_open("database.db", &DB);
        char *messageError;
        exit = sqlite3_exec(DB, command.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK)
        {
            std::cout << "Couldn't add Password " << std::endl;
            sqlite3_free(messageError);
        }
        else
        {
            std::cout << "Password was added successfully!" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    sqlite3_close(DB);
    return 0;
}

void get_all_passwords(User &user)
{
    sqlite3 *DB;
    std::string user_id = std::to_string(user.get_id());
    int exit = sqlite3_open("database.db", &DB);
    std::string command = "SELECT * FROM password WHERE user_id=" + user_id;

    exit = sqlite3_exec(DB, command.c_str(), get_all_passwords_callback, NULL, NULL);

    sqlite3_close(DB);
}

int get_user_callback(void *notUsed, int argc, char **argv, char **col_name)
{
    USER.set_id(atoi(argv[0]));
    USER.set_username(argv[1]);
    USER.set_password(argv[2]);
    USER.set_pin(argv[3]);

    return 0;
}

int get_group_callback(void *notUsed, int argc, char **argv, char **col_name)
{
    GROUP.set_id(atoi(argv[0]));
    GROUP.set_user(&USER);
    GROUP.set_name(argv[1]);

    return 0;
}

int get_all_groups_callback(void *notUsed, int argc, char **argv, char **col_name)
{
    PasswordGroup pg;
    pg.set_id(atoi(argv[0]));
    pg.set_user(&USER);
    pg.set_name(argv[2]);
    GROUP_LIST.push_back(pg);
    return 0;
}

int get_all_passwords_callback(void *notUsed, int argc, char **argv, char **col_name)
{
    Password p;
    p.set_id(atoi(argv[0]));
    p.set_user(&USER);
    p.set_app(argv[2]);
    p.set_group(&GROUP);
    p.set_username(argv[4]);
    p.set_email(argv[5]);
    p.set_password(argv[6]);
    PASSWORD_LIST.push_back(p);
    return 0;
}