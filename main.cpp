#include <iostream>
#include "Menu.h"


#include "Password.h"
#include "PasswordManager.h"

int main() {

//    Password password("haslo do gmail", "jestemNajlepszy123", "praca");
//    std::cout << password.toString();

//    Menu menu;
//    menu.choice();
    PasswordManager passwordManager;
    std::string password = passwordManager.generatePassword(20, true, true);
    std::cout << password << std::endl;
    std::string odp = passwordManager.checkPassword(password);
    std::cout << odp;

    return 0;
}
