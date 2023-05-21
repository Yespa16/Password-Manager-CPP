#include <iostream>
#include <string>


class Validator{
public:
    void Email(std::string& email);
    void Username(std::string& username);
    void UsernameAndEmail(std::string& username, std::string& email);
    void Text(std::string& txt);
};