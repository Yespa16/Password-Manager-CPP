#include <string>

class User {
  // int validate(std::string, std::string, int);
  std::string hash(std::string text);

private:
  std::string username;
  std::string password;
  std::string pin;

public:
    User();
    User(std::string _u, std::string _p, std::string _pin);
    ~User();

  int validate(std::string username, std::string password, std::string pin);
};