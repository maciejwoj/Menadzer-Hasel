//
// Created by Maciek on 27.05.2023.
//
#include <iostream>
#include <fstream>
#include "Menu.h"
#include "PasswordManager.h"

using namespace std;
PasswordManager passwordManager;
Categories categories;

Menu::Menu() = default;

[[noreturn]] void Menu::choice() {
    string files[] = {"maciek.txt", "radek.txt", "wojtek.txt"};
    int size = sizeof(files) / sizeof(files[0]);
    string password;
    string absolutePath;
    bool end = false;
    while (!end) {
        cout << "~~~~~~~~~~s27578~~~~~~~~~~\n" <<
             "1. Open file\n" <<
             "2. Exit\n" <<
             "~~~~~~~~~~s27578~~~~~~~~~~\n";

        cout << "Enter your choice: ";
        int ch;
        cin >> ch;


        switch (ch) {
            case 1: {
                int d0;
                cout << "Which file you wanna open: " << endl;
                for (int i = 0; i < size; i++) {
                    cout <<i+1<<". "<< files[i] << endl;
                }
                cout << "4. enter absolute path to the file";
                cin >> d0;
                if(d0 == 1 or d0 == 2 or d0 == 3){
                    absolutePath = "..\\"+files[d0-1];
                }else{
                    cout << "Enter path to the file:  ";
                    cin >> absolutePath;
                }


                ifstream file(absolutePath);
                if (!file) {
                    cout << "there is no file with this name, please try again" << endl;
                    break;
                }
                passwordManager.loadFile(absolutePath);
                cout << "last time someone open this file: ";
                passwordManager.readTimestamp();
                cout << endl;
                cout << "enter password to that file: " << endl;
                cin >> password;
                passwordManager.uncodeFile(password);
                for(int i = 0; i < passwordManager.data.size();i++){
                    categories.addCategory(passwordManager.data[i][2]);
                }
                cout << "example: " << passwordManager.data[0][0]<< endl << endl;

                cout << "whether the file is properly decoded ? " << endl <<
                     "1. Yes " << endl <<
                     "2. No" << endl <<
                     "Enter your choice: ";
                int d1;
                cin >> d1;
                bool end2 = false;
                while (!end2) {
                    switch (d1) {
                        case 1: {
                            cout << "~~~~~~~~~~s27578~~~~~~~~~~\n" <<
                                 "1. search password\n" <<
                                 "2. sort passwords\n" <<
                                 "3. add password\n" <<
                                 "4. edit password\n" <<
                                 "5. delete passwords\n" <<
                                 "6. add category\n" <<
                                 "7. delete category\n" <<
                                 "8. show file\n" <<
                                 "9. Exit\n" <<
                                 "~~~~~~~~~~s27578~~~~~~~~~~\n";

                            cout << "Enter your choice: ";
                            int d2;
                            cin >> d2;
                            switch (d2) {
                                case 1: {
                                    string search;
                                    cout << "enter fraze to search: ";
                                    cin >> search;
                                    passwordManager.searchPassword(search);
                                    break;
                                }
                                case 2: {
                                    int d3;
                                    cout << "by what you wanna sort" << endl <<
                                         "1. Name" << endl <<
                                         "2. password" << endl <<
                                         "3. category" << endl;
                                    cin >> d3;
                                    passwordManager.sortPassword(d3 - 1);
                                    break;
                                }
                                case 3: {
                                    string passwordName;
                                    cout << "enter name: ";
                                    cin >> passwordName;
                                    cout << endl;
                                    categories.showCategoryList();
                                    int passwordCategory;
                                    cout << "enter category number: ";
                                    cin >> passwordCategory;
                                    cout << endl;

                                    cout << "chose option " << endl <<
                                         "1. Add your own " << endl <<
                                         "2. generate password" << endl <<
                                         "Enter your choice: ";
                                    int d4;
                                    cin >> d4;
                                    switch (d4) {
                                        case 1: {
                                            string passwordToAdd;
                                            cout << "enter password: ";
                                            cin >> passwordToAdd;
                                            cout << endl;
                                            cout << passwordManager.checkPassword(passwordToAdd) << endl;
                                            int d5;
                                            cout << "Do you want to add website and login?" << endl <<
                                                 "1. YES " << endl <<
                                                 "2. NO" << endl <<
                                                 "Enter your choice:  ";
                                            cin >> d5;
                                            switch (d5) {
                                                case 1: {
                                                    string passwordWebsite;
                                                    cout << "enter website: ";
                                                    cin >> passwordWebsite;
                                                    string passwordLogin;
                                                    cout << "enter login: ";
                                                    cin >> passwordLogin;
                                                    passwordManager.addPassword(
                                                            Password(passwordName, passwordToAdd,
                                                                     categories.categoriesList[passwordCategory - 1],
                                                                     passwordWebsite, passwordLogin));
                                                    break;
                                                }
                                                case 2: {
                                                    passwordManager.addPassword(
                                                            Password(passwordName, passwordToAdd,
                                                                     categories.categoriesList[passwordCategory - 1]));
                                                    break;
                                                }
                                            }

                                            passwordManager.showFile();
                                            break;
                                        }
                                        case 2: {
                                            string passwordToAdd2;
                                            int passwordLength;
                                            bool upperCase;
                                            int upperCased;
                                            bool specialChars;
                                            int specialCharsd;
                                            cout << "enter length of your password: ";
                                            cin >> passwordLength;
                                            cout << "Do you want upperCase in your password?" << endl <<
                                                 "1. YES " << endl <<
                                                 "2. NO" << endl <<
                                                 "Enter your choice:  ";
                                            cin >> upperCased;
                                            if (upperCased == 1) {
                                                upperCased = true;
                                            } else {
                                                upperCased = false;
                                            }
                                            cout << "Do you want special character in your password?" << endl <<
                                                 "1. YES " << endl <<
                                                 "2. NO" << endl <<
                                                 "Enter your choice:  ";
                                            cin >> specialCharsd;
                                            if (specialCharsd == 1) {
                                                specialChars = true;
                                            } else {
                                                specialChars = false;
                                            }

                                            passwordToAdd2 = PasswordManager::generatePassword(passwordLength,
                                                                                               upperCase,
                                                                                               specialCharsd);
                                            int d6;
                                            cout << "Do you want to add website and login?" << endl <<
                                                 "1. YES " << endl <<
                                                 "2. NO" << endl <<
                                                 "Enter your choice:  ";
                                            cin >> d6;
                                            switch (d6) {
                                                case 1: {
                                                    string passwordWebsite;
                                                    cout << "enter website: ";
                                                    cin >> passwordWebsite;
                                                    string passwordLogin;
                                                    cout << "enter login: ";
                                                    cin >> passwordLogin;
                                                    passwordManager.addPassword(
                                                            Password(passwordName,
                                                                     passwordToAdd2,
                                                                     categories.categoriesList[passwordCategory - 1],
                                                                     passwordWebsite, passwordLogin));
                                                    break;
                                                }
                                                case 2: {
                                                    passwordManager.addPassword(
                                                            Password(passwordName,
                                                                     passwordToAdd2,
                                                                     categories.categoriesList[passwordCategory - 1]));
                                                    break;
                                                }
                                            }
                                            passwordManager.showFile();


                                        }
                                            break;
                                    }
                                    break;
                                }
                                case 4: {
                                    cout << "which password you wanna edit?" << endl;
                                    passwordManager.showFile();
                                    int passwordEditIndex;
                                    cout << "enter number: ";
                                    cin >> passwordEditIndex;
                                    if(passwordEditIndex < passwordManager.data.size()+1) {
                                        passwordManager.editPassword(passwordEditIndex - 1);
                                        cout<<"your password has been successfully edited "<<endl;
                                    }else{
                                        cout<<"you have chosen a number that is not available";
                                    }
                                    passwordManager.showFile();
                                    break;
                                }
                                case 5: {
                                    cout << "which password you wanna delete?" << endl;
                                    passwordManager.showFile();
                                    int passwordIndex;
                                    cout << "enter number: ";
                                    cin >> passwordIndex;
                                    if(passwordIndex < passwordManager.data.size() +1) {
                                        passwordManager.deletePassword(passwordIndex - 1);
                                    }else{
                                        cout<<"you have chosen a number that is not available";
                                    }
                                    break;
                                }
                                case 6: {
                                    string categoryName;
                                    cout << "enter category name: ";
                                    cin >> categoryName;
                                    categories.addCategory(categoryName);
                                    cout << "category has been added";
                                    break;
                                }
                                case 7: {
                                    cout << "Which category you want to delete?"<<endl;
                                    categories.showCategoryList();
                                    int categoryIndex;
                                    cout << "enter number: ";
                                    cin >> categoryIndex;
                                    if(categoryIndex < categories.categoriesList.size()) {
                                        cout << categories.categoriesList[categoryIndex - 1] << endl;
                                        passwordManager.deleteCategory(categories.categoriesList[categoryIndex - 1]);
                                        categories.deleteCategory(categoryIndex - 1);
                                    }else{
                                        cout<<"choose number from the list" << endl;
                                    }
                                    break;
                                }
                                case 8: {
                                    passwordManager.showFile();
                                    break;
                                }
                                case 9:
                                    passwordManager.codeFile(password);
                                    passwordManager.addTimestamp();
                                    passwordManager.saveFile(absolutePath);
                                    cout << "Your file has been safe. Exiting the program.\n";
                                    end2 = true;
                                    end = true;
                                    break;
                                default:
                                    cout << "Invalid choice. Please try again.\n";
                                    break;

                            }
                            break;
                        }
                        case 2:
                            cout << "you enter wrong password, please try again" << endl;
                            break;
                    }
                }
                break;
            }

            case 2:
                cout << "Exiting the program.\n";
                end = true;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}