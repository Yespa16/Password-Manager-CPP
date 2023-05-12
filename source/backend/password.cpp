#include <string>
#include <iostream>
#include "user.h"
#include "password.h"


Password::Password(User* _u, std::string _email, std::string _username, PasswordGroup* _group, std::string _password) {

        if (_username.length() == 0 && _email.length() == 0 ) {
            std::cout <<  "Email and Username are empty, please provide at least one of them" << std::endl;
            //delete this;
            return;
        }
        this->user = _u;
        this->email = _email;
        this->username = _username;
        this->group = _group;
        this->password = _password;
    }


Password::~Password(){
        user = nullptr;
        group = nullptr;
    }