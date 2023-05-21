#include <string>

class User
{
  

private:
  std::string& hash(std::string& text);
  int id;
  std::string username;
  std::string password;
  std::string pin;

  int validate(std::string username, std::string password, std::string pin, int id);

public:
  User();
  User(std::string _u, std::string _p, std::string _pin, int _id = 0);
  ~User();

  int get_id();
  std::string& get_username();
  std::string& get_password();
  std::string& get_pin();

  void set_id(int);
  void set_username(const char *);
  void set_password(const char *);
  void set_pin(const char *);
};