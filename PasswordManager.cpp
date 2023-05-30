//
// Created by Maciek on 27.05.2023.
//
#include "PasswordManager.h"
#include <string>
#include <cstdlib>
#include <ctime>

PasswordManager::PasswordManager() {

}

void PasswordManager::loadFile(std::string path) {

}

void PasswordManager::saveFile(std::string path) {

}

void PasswordManager::addPassword(Password password) {

}
void PasswordManager::editPassword(Password password) {

}
void PasswordManager::deletePassword(Password password) {

}
void PasswordManager::searchPassword(std::string search) {

}
void PasswordManager::sortPassword(std::string sortBy) {

}

std::string PasswordManager::generatePassword(int length, bool upperCase, bool specialChars) {
    std::string newPassword;
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < length; i++) {
        int r = rand() % 3;

        if (r == 0 && upperCase) {
            newPassword += static_cast<char>(rand() % 26 + 65);
        } else if (r == 1) {
            newPassword += static_cast<char>(rand() % 26 + 97);
        } else if (r == 2 && specialChars) {
            newPassword += static_cast<char>(rand() % 15 + 33);
        } else {
            i--;
        }
    }
    return newPassword;
}



std::string PasswordManager::checkPassword(const std::string& password) {
    if(password.length() < 8){
        return "weak";
    }
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;
    for(char c : password){
        if(std::isupper(c)){
            hasUpperCase = true;
        }
        if(std::islower(c)){
            hasLowerCase = true;
        }
        if(std::isdigit(c)){
            hasDigit = true;
        }
        if(!std::isalnum(c)){
            hasSpecialChar = true;
        }
    }



    if(hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar || hasUpperCase && hasLowerCase && !hasDigit && hasSpecialChar){
        return "strong";
    }else if(hasUpperCase && hasLowerCase && hasDigit && !hasSpecialChar){
        return "normal";
    }else
        return "weak";


}
