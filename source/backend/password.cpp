#include "password.h"

PasswordGroup::PasswordGroup() : id(0), user(nullptr), name(""){};

PasswordGroup::PasswordGroup(User *_user, std::string _name, int _id) : id(_id), user(_user), name(_name){};

PasswordGroup::~PasswordGroup()
{
    user = nullptr;
}

void PasswordGroup::set_id(int _id)
{
    this->id = _id;
}

int PasswordGroup::get_id()
{
    return id;
}

std::string PasswordGroup::get_name()
{
    return name;
}

void PasswordGroup::set_name(std::string _name)
{
    this->name = _name;
}

User *PasswordGroup::get_user()
{
    return user;
}

void PasswordGroup::set_user(User *u)
{
    user = u;
}

Password::Password() : id(0), user(nullptr), group(nullptr), email(""), username(""), password("") {}

Password::Password(User *_u, std::string _app, std::string _email, std::string _username, PasswordGroup *_group, std::string _password, int _id)
{

    if (_username.length() == 0 && _email.length() == 0)
    {
        std::cout << "Email and Username are empty, please provide at least one of them" << std::endl;
        // delete this;
        return;
    }
    this->id = _id;
    this->user = _u;
    this->email = _email;
    this->username = _username;
    this->group = _group;
    this->password = _password;
}

Password::~Password()
{
    user = nullptr;
    group = nullptr;
}

User *Password::get_user()
{
    return user;
}

PasswordGroup *Password::get_group()
{
    return group;
}

std::string Password::get_app()
{
    return app;
}

std::string Password::get_email()
{
    return email;
}

std::string Password::get_username()
{
    return username;
}

std::string Password::get_password()
{
    return password;
}

void Password::set_id(int _id)
{
    id = _id;
}

void Password::set_user(User *_u)
{
    user = _u;
}

void Password::set_group(PasswordGroup *p)
{
    group = p;
}

void Password::set_app(std::string _app)
{
    app = _app;
}

void Password::set_email(std::string _email)
{
    email = _email;
}

void Password::set_username(std::string _u)
{
    username = _u;
}

void Password::set_password(std::string _p)
{
    password = _p;
}