//
// Created by Maciek on 27.05.2023.
//
#include "PasswordManager.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;
PasswordManager::PasswordManager() {

}

void PasswordManager::loadFile(const string& path) {
    ifstream file(path);
    if(!file){
        cout << "there is no file with this name"<<endl;
    }
    string line;
    while (getline(file,line)){
        vector<string>row;
        istringstream iss(line);
        string word;
        while(getline(iss,word,';')){
            row.push_back(word);
        }
        data.push_back(row);
    }
}

string PasswordManager::encryption(const string &password, const string& word) {

    string encrypted;
    for (int i = 0; i < word.length(); i++) {
        int numberCode = (word[i] + password[i % password.length()]) % 256;
            encrypted += numberCode;
    }

    return encrypted;
}

string PasswordManager::decryption(const string &password, const string& word) {

    string decrypted;
    for (int i = 0; i < word.length(); i++) {
        int numberCode = (word[i] - password[i % password.length()]) % 256;
        if(word[i] - password[i % password.length()] < 1){
            numberCode = (word[i] - password[i % password.length()]) + 256;
        }
        decrypted += numberCode;
    }

    return decrypted;
}

void PasswordManager::codeFile(const string& password) {

}

void PasswordManager::uncodeFile(const string& password){

}

void PasswordManager::saveFile(std::string path) {
    ofstream file(path);
    if(!file){
        cout << "there is no file with this name"<<endl;
    }

    for (const auto& row : data) {
        for (const auto& word : row) {
            file << word << "; ";
        }
        file << endl;
    }

    file.close();
}


void PasswordManager::showFile() {
        for (const auto& row : data) {
        for (const auto& word : row) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
}

void PasswordManager::addPassword(Password password) {
    vector<string>newRow;
    stringstream ss(password.toString());
    string word;
    while(getline(ss, word, ';')){
        newRow.push_back(word);
    }
    data.push_back(newRow);
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
