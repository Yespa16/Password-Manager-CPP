#! bin/bash
clear
g++ main.cpp database.cpp backend/user.cpp  backend/password.cpp -l sqlite3
./a.exe