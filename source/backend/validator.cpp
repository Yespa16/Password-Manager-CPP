#include "validator.h"


void Validator::Text(std::string& txt)  {
        if (txt.length() == 0){
            throw std::logic_error("Invalid input!");
        }
}

void Validator::Username(std::string& username){
    if(username.length() == 0){
        throw std::logic_error("Username must not be empty");
    }
}

void Validator::Email(std::string& email){
    if (email.length() == 0){
        throw std::logic_error("Email must not be empty");
    }
}


void Validator::UsernameAndEmail(std::string& username, std::string& email){
    if (username.length() == 0 || email.length() == 0){
        throw std::logic_error("Either Username or Email must be specified");
    }
}