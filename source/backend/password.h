#include <string>
#include <iostream>
#include "user.h"



class PasswordGroup{
private:
    std::string name;
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