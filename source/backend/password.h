#include <string>
#include <iostream>
#include "user.h"



class PasswordGroup{
private:
    int id;
    User* user;
    std::string name;

public:
    PasswordGroup();
    PasswordGroup(User* _user, std::string _name);
    ~PasswordGroup();


    int get_id();
    void set_id(int _id);
    void set_user(User*);
    std::string get_name();
    void set_name(std::string);
};


class Password{
private:
    User* user;
    std::string email;
    std::string username;
    PasswordGroup* group;
    std::string password;

public:
    Password(User* _u, std::string _email, std::string _username, PasswordGroup* _group, std::string _password);
    ~Password();
    
};