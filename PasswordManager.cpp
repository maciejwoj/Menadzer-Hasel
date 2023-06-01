//
// Created by Maciek on 27.05.2023.
//
#include "PasswordManager.h"
#include "Categories.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;
PasswordManager::PasswordManager() = default;

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
    for(int i = 0; i < data.size(); i++){
        for(int j = 0; j < data[i].size(); j++){
            data[i][j] = encryption(password, data[i][j]);
        }
    }

}

void PasswordManager::uncodeFile(const string& password){
    for(int i = 0; i < data.size(); i++){
        for(int j = 0; j < data[i].size(); j++){
            data[i][j] = decryption(password, data[i][j]);
        }
    }
}

void PasswordManager::saveFile(std::string path) {
    ofstream file(path);
    if(!file){
        cout << "there is no file with this name"<<endl;
    }

    for (const auto& row : data) {
        for (const auto& word : row) {
            file << word << ";";
        }
        file << endl;
    }

    file.close();
}


void PasswordManager::showFile() {
    int index = 1;
    for (const auto& row : data) {
        cout<<index<<". ";
        index ++;
        for (const auto& word : row) {
            cout << word << " ";
        }
    cout << endl;
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
void PasswordManager::editPassword(int passwordEditIndex) {
    cout << data[passwordEditIndex][1]<<endl;
    string newEditPassword;
    cout << "enter your edit password here:  ";
    cin >> newEditPassword;
    data[passwordEditIndex][1] = newEditPassword;
}
void PasswordManager::deletePassword(int passwordIndex) {
    data.erase(data.begin() + passwordIndex);
}
void PasswordManager::searchPassword(string search) {
    bool isInFile = false;
    for(int i = 0; i < data.size(); i++){
        for(int j = 0; j < data[i].size(); j++){
            if(search == data[i][j]){
                isInFile = true;
                for(auto e : data[i]){
                    cout << e << " ";
                }
            }
        }
    }
    if (!isInFile){
        cout<<"this password is not in file";
    }
    cout << endl;
}
void PasswordManager::sortPassword(int indexColumn){
    sort(data.begin(),data.end(), [indexColumn](vector<basic_string<char>> row1, const vector<basic_string<char>> row2){
        return row1[indexColumn] < row2[indexColumn];
    });
}

void PasswordManager::deleteCategory(std::string categoryName) {
    for(int i = 0; i < data.size(); i++){
        if(data[i][2] == categoryName){
            data.erase(data.begin() + i);
            i--;
        }
    }
}

string PasswordManager::generatePassword(int length, bool upperCase, bool specialChars) {
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
    bool isInFile = false;
    for(int i = 0; i < data.size(); i++){
        for(int j = 0; j < data[i].size(); j++){
            if(password == data[i][j]){
                isInFile = true;
            }
        }
    }
    if (isInFile){
        return "this password is already been used";
    }

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
        return "your password is strong";
    }else if(hasUpperCase && hasLowerCase && hasDigit && !hasSpecialChar){
        return "your password is normal";
    }else
        return "your password is weak";
}

