#include "user.h"
#include <string>
#include "iostream"

User::User() : id(0), username(""), password(""), pin(""){};
User::~User() {}

User::User(std::string _u, std::string _p, std::string _pin, int _id)
{
  int v = validate(_u, _p, _pin, _id);
  if (!v)
  {
    this->id = _id;
    this->username = _u;
    this->password = hash(_p);
    this->pin = _pin;
  }
  else
  {
    std::cout << "Invalid Data \n";
  }
}

int User::validate(std::string username, std::string password, std::string pin, int id)
{
  if (username.length() == 0 || password.length() == 0 || pin.length() == 0 || pin.length() > 4 || id < 0)
  {
    return 1;
  }
  return 0;
}

std::string User::hash(std::string text)
{
  // Implement hash algorithm later
  return text;
}

int User::get_id()
{
  return id;
}

std::string User::get_username()
{
  return username;
}

std::string User::get_password()
{
  return password;
}

std::string User::get_pin()
{
  return pin;
}

void User::set_id(int _id)
{
  id = _id;
}

void User::set_username(const char *u)
{
  username = u;
}

void User::set_password(const char *p)
{
  password = hash(p);
}

void User::set_pin(const char *_pin)
{
  pin = _pin;
}