#include "password.h"

Validator Validate;

Password::Password() : id(0), user(nullptr), app(""), password("") {}

Password::Password(User *_u, std::string _app,  std::string _password, int _id)
{
    if (_id <= 0) {
        throw std::logic_error("Id must be greater than 0");
    }
    this->id = _id;
    this->user = _u;
    this->app = std::move(_app);

    if(_password.length() == 0){
        throw std::logic_error("Password must be not empty");
    }
    this->password = std::move(_password);

    }
void Password::set_id( int _id) {
        if (_id <= 0) {
            throw std::logic_error("Id must be greater than 0");
        }
        this->id = _id;
    }
void Password::set_password(std::string _password) {
        if (_password.length() == 0) {
            throw std::logic_error("Password must be not empty");
        }
        this->password = std::move(_password);
}


std::string Password::add_sql() {
    
    std::string user_id = std::to_string(get_user()->get_id());
    std::string app = get_app();
    std::string password = get_password();

    std::string command = "INSERT INTO password (user_id, app, email, username, password) VALUES(" + user_id + ", '" + app + "', '', '', '" + password + "');";
    return command;
}



EmailPassword::EmailPassword():Password(), email(""), phone_number(""), reserve_email(""){}


EmailPassword::EmailPassword(User *_u, std::string _app,  std::string _password, int _id, std::string email, std::string phone_number, std::string reserve_email){
    Password(_u, _app, _password, _id);
    Validate.Email(email);
    this->email = std::move(email);
    this->phone_number = std::move(phone_number);
    this->reserve_email = std::move(reserve_email);
}


void EmailPassword::set_email(std::string email) {
    Validate.Email(email);
    this->email = std::move(email);
}


void EmailPassword::set_phone_number(std::string phone_number){
    this->phone_number = std::move(phone_number);
}

void EmailPassword::set_reserve_email(std::string reserve){
    this->reserve_email = std::move(reserve);
}



std::string EmailPassword::add_sql(){

    std::string user_id = std::to_string(get_user()->get_id());
    std::string app = get_app();
    std::string password = get_password();

    std::string command = "INSERT INTO password (user_id, app, email, username, password, phone_nubmer, reserve_email) VALUES(" + user_id +  ", '" + app + "', '" + email + "', '" + "'', " + "', '" + password + "', '" + phone_number + "', '" + reserve_email +  " ');";
    return command;
}



GamePassword::GamePassword():Password(), username(""), email(""), level(""), description(""){}


GamePassword::GamePassword(User *_u, std::string _app,  std::string _password, int _id, std::string _username, std::string _email, std::string _level, std::string _description){
    Password(_u, _app, _password, _id);
    Validate.UsernameAndEmail(_username, _email);
    this->username = std::move(_username);
    this->email = std::move(_email);
    this->level = std::move(_level);
    this->description = std::move(_description);    
}


void GamePassword::set_username(std::string username){
    Validate.Username(username);
    this->username = std::move(username);
}


void GamePassword::set_email(std::string email){
    Validate.Email(email);
    this->email = std::move(email);
}


std::string GamePassword::add_sql(){
    
    std::string user_id = std::to_string(get_user()->get_id());
    std::string app = get_app();
    std::string password = get_password();
    std::string command = "INSERT INTO password (user_id, app, email, username, password, phone_nubmer, reserve_email, level, description) VALUES(" + user_id +  ", '" + app + "', '" + email + "', '" + username + "', '" + password + "', '" + "'', " + "', '" + "'', " +  "', '" + level + "', '" + description + " ');";
    return command;
}