//
// Created by Maciek on 30.05.2023.
//

#ifndef MENADZER_HASEL_PASSWORDMANAGER_H
#define MENADZER_HASEL_PASSWORDMANAGER_H
#include <iostream>
#include <vector>
#include "Password.h"

class PasswordManager{
public:
    PasswordManager();
    std::vector<std::vector<std::string>>data;
    void loadFile(const std::string& path);
    void saveFile(std::string path);
    void addPassword(Password password);
    void editPassword(Password password);
    void deletePassword(Password password);
    void searchPassword(std::string search);
    void sortPassword(std::string sortBy);
    static std::string encryption(const std::string& password, const std::string& word);
    static std::string decryption(const std::string& password, const std::string& word);
    void codeFile(const std::string& password);
    void uncodeFile(const std::string& password);
    static std::string generatePassword(int length, bool upperCase, bool specialChars);
    std::string checkPassword(const std::string& password);
    void showFile();


};

#endif //MENADZER_HASEL_PASSWORDMANAGER_H
