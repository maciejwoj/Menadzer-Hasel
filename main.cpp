#include <iostream>
#include "Menu.h"


#include "Password.h"
#include "PasswordManager.h"

int main() {

    //    Menu menu;
//    menu.choice();


    Password password("haslo do binance", "jestemNajlepszy!@!@", "hobby");
//    std::cout << password.toString() << std::endl;


    PasswordManager passwordManager;


    std::string test1 = passwordManager.encryption("KOra!", "M4cI#K");
    std::cout << test1 << std::endl;
    std::string test2 = passwordManager.decryption("KOra!",test1);
    std::cout << test2;
//    std::string password = passwordManager.generatePassword(20, true, true);
//    std::cout << password << std::endl;
//    std::string odp = passwordManager.checkPassword(password);
//    std::cout << odp;

//    passwordManager.loadFile("..\\maciek.txt");
//    std::cout << passwordManager.data[0][1];
//    passwordManager.addPassword(password);
//    Password password1("haslo do revoluta", "KHJkhj234hj1!", "hobby","revolut.com", "maciunio");
//    passwordManager.addPassword(password1);
//    passwordManager.showFile();
//    passwordManager.saveFile("..\\maciek.txt");
//



    return 0;
}
