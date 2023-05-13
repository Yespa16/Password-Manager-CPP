#include "password.h"



PasswordGroup::PasswordGroup(): user(nullptr), name("") {};

PasswordGroup::PasswordGroup(User* _user, std::string _name): user(_user), name(_name){};

PasswordGroup::~PasswordGroup() {user = nullptr;}

void PasswordGroup::set_id(int _id){
    id = _id;
}

int PasswordGroup::get_id(){
    return id;
}

std::string PasswordGroup::get_name(){
    return name;
}

void PasswordGroup::set_name(std::string _name) {
    name = _name;
}

void PasswordGroup::set_user(User* u){
    user = u;
}


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


