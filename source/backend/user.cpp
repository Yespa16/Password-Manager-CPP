#include "user.h"
#include <string>


User::User() : username(""), password(""), pin(0){};
User::~User() {}

User::User(std::string _u, std::string _p, std::string _pin) {
    int v = validate(_u, _p, _pin);
    if (!v) {
      this->username = _u;
      this->password = hash(_p);
      this->pin = _pin;
    }
  }

int User::validate(std::string username, std::string password, std::string pin) {
    if (username.length() == 0 || password.length() == 0 || pin.length() == 0 || pin.length() > 4) {
      return 1;
    }
    return 0;
  }

std::string User::hash(std::string text) {
    // Implement hash algorithm later
    return text;
  }
// class User {

// private:
//   std::string username;
//   std::string password;
//   int pin;

// public:
//   ~User() {
//     username = nullptr;
//     password = nullptr;
//   }
// };