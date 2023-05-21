#include <string>
#include <iostream>
#include "user.h"
#include "validator.h"



class Password
{
private:
    int id;
    User* user;
    std::string app;
    std::string password;


public:
    Password();
    Password(User *_u, std::string _app, std::string _password, int _id = 0);
    ~Password(){}

    User* get_user(){return this->user;}
    std::string& get_app() {return this->app;}
    std::string& get_password() {return this->password;}

    void set_id(int _id);
    void set_user(User* _u) {this->user = _u;}
    void set_app(std::string _app) {this->app = std::move(_app);}
    void set_password(std::string _password);

    virtual std::string add_sql();
};



class EmailPassword: public Password{ 
private:
    std::string email;
    std::string phone_number;
    std::string reserve_email;

public:
    EmailPassword();
    EmailPassword(User *_u, std::string _app,  std::string _password, int _id, std::string email, std::string phone_number, std::string reserve_email);
    ~EmailPassword(){}

    std::string& get_email() {return this->email;}
    std::string& get_phone_number() {return this->phone_number;}
    std::string& get_reserve_email() {return this->reserve_email;}

    void set_email(std::string email);
    void set_phone_number(std::string phone_number);
    void set_reserve_email(std::string reserve);

    virtual std::string add_sql();
};



class GamePassword: public Password{ 
private:
    std::string username;
    std::string email;
    std::string level;
    std::string description;

public:
    GamePassword();
    GamePassword(User *_u, std::string _app,  std::string _password, int _id, std::string _username, std::string _email, std::string _level, std::string _description);
    ~GamePassword(){}

    std::string& get_username() {return this->username;}
    std::string& get_level() {return this->level;}
    std::string& get_email() {return this->email;}
    std::string& get_description() {return this->description;}

    void set_username(std::string username);
    void set_email(std::string email);
    void set_level(std::string level) {this->level = std::move(level);}
    void set_description(std::string description) {this->description = std::move(description);}

    virtual std::string add_sql();
};
