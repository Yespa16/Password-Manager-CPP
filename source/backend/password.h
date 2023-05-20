#include <string>
#include <iostream>
#include "user.h"

class PasswordGroup
{
private:
    int id;
    User *user;
    std::string name;

public:
    PasswordGroup();
    PasswordGroup(User *_user, std::string _name, int _id = 0);
    ~PasswordGroup();

    int get_id();
    void set_id(int _id);
    void set_user(User *);
    User *get_user();
    std::string get_name();
    void set_name(std::string);
};

class Password
{
private:
    int id;
    User *user;
    PasswordGroup *group;
    std::string app;
    std::string email;
    std::string username;
    std::string password;

public:
    Password();
    Password(User *_u, std::string _app, std::string _email, std::string _username, PasswordGroup *_group, std::string _password, int _id = 0);
    ~Password();

    User *get_user();
    PasswordGroup *get_group();
    std::string get_app();
    std::string get_email();
    std::string get_username();
    std::string get_password();

    void set_id(int);
    void set_user(User *);
    void set_group(PasswordGroup *);
    void set_app(std::string);
    void set_email(std::string);
    void set_username(std::string);
    void set_password(std::string);
};