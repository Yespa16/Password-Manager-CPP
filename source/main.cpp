#include "database.h"



int main() {
    sqlite3* DB;
    DatabaseClass db("database.db", DB);
    User u("Yespa", "USER PASSWORD", "1547", 1);
    Password p(&u, "apppp", "generalp", 1);
    try{
    db.create_db();
    db.create_user_table();
    db.create_password_table();

    // db.create_user(u);
    db.add_password(&p);
    db.get_user("Yespa");
    std::cout << Data::GET_USER().get_password();
    } catch(int e) {
        std::cout << db.error_message;
    }
    EmailPassword ep(&u, "emailapp", "password", 1, "email", "+374", "reserve");
    GamePassword gp(&u, "appasd", "password", 1, "username", "email", "level 1", "desc");


    
    return 0;
}