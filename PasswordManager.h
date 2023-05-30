//
// Created by Maciek on 30.05.2023.
//

#ifndef MENADZER_HASEL_PASSWORDMANAGER_H
#define MENADZER_HASEL_PASSWORDMANAGER_H
#include <iostream>
#include "Password.h"

class PasswordManager{
public:
    PasswordManager();
    void loadFile(std::string path);
    void saveFile(std::string path);
    void addPassword(Password password);
    void editPassword(Password password);
    void deletePassword(Password password);
    void searchPassword(std::string search);
    void sortPassword(std::string sortBy);
    static std::string generatePassword(int length, bool upperCase, bool specialChars);
    std::string checkPassword(const std::string& password);


};

#endif //MENADZER_HASEL_PASSWORDMANAGER_H
