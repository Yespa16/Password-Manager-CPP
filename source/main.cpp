#include "database.h"

extern User USER;
extern PasswordGroup GROUP;
extern std::vector<PasswordGroup> GROUP_LIST;
extern std::vector<Password> PASSWORD_LIST;

int main() {
    const char *dir = "./database.db";
    sqlite3* DB;
    create_db(dir, DB);
    create_user_table(DB);
    create_password_group_table(DB);
    create_password_table(DB);
    User u("Yespa", "EDO", "1537");
    create_user(u);
    get_user("Yespa");
    PasswordGroup pg(&USER, "GROUP2");
    add_group(pg);
    Password p(&USER, "app", "email1", "userna1me", &GROUP, "P1assword123");
    add_password(p);
    Password p2(&USER, "app", "email1", "userna1me", &GROUP, "P1assword123"); 
    
    get_all_groups(USER);
    get_all_passwords(USER);
    return 0;
}