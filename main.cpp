#include <iostream>
#include <fstream>
#include "Menu.h"


#include "Password.h"
#include "PasswordManager.h"
using namespace std;

int main() {

    Menu menu;
    menu.choice();


//    Categories categories2;
//    PasswordManager passwordManager2;
//    passwordManager2.loadFile("..\\wojtek.txt");
//    passwordManager2.addTimestamp();
//    passwordManager2.showFile();
//    passwordManager2.saveFile("..\\wojtek.txt");
//    passwordManager2.readTimestamp();
//    passwordManager2.uncodeFile("hasloDoWojtek");
//    passwordManager2.showFile();

//    passwordManager2.uncodeFile("hasloDoWojtek");
//    for(int i = 0; i < passwordManager2.data.size();i++){
//        categories2.addCategory(passwordManager2.data[i][2]);
//    }
//    passwordManager2.showFile();

//    string passwordName;
//    cout << "enter name: ";
//    cin >> passwordName;
//    cout << endl;
//    categories2.showCategoryList();
//    int passwordCategory;
//    cout << "enter category number: ";
//    cin >> passwordCategory;
//    cout << endl;
//
//    cout << "chose option " << endl <<
//         "1. Add your own " << endl <<
//         "2. generate password" << endl <<
//         "Enter your choice: ";
//    int d4;
//    cin >> d4;
//    switch (d4) {
//        case 1: {
//            string passwordToAdd;
//            cout << "enter password: ";
//            cin >> passwordToAdd;
//            cout << endl;
//            cout << passwordManager2.checkPassword(passwordToAdd)<<endl;
//            int d5;
//            cout << "Do you want to add website and login?"<< endl <<
//            "1. YES " << endl <<
//            "2. NO" << endl <<
//            "Enter your choice:  ";
//            cin >> d5;
//            switch(d5){
//                case 1:{
//                    string passwordWebsite;
//                    cout << "enter website: ";
//                    cin >> passwordWebsite;
//                    string passwordLogin;
//                    cout << "enter login: ";
//                    cin >> passwordLogin;
//                    passwordManager2.addPassword(
//                            Password(passwordName,passwordToAdd,
//                                     categories2.categoriesList[passwordCategory-1],
//                                     passwordWebsite,passwordLogin));
//                    break;
//                }
//                case 2:{
//                    passwordManager2.addPassword(
//                            Password(passwordName,passwordToAdd,
//                                     categories2.categoriesList[passwordCategory-1]));
//                    break;
//                }
//            }
//
//            passwordManager2.showFile();
//            break;
//        }
//        case 2:{
//            string passwordToAdd2;
//            int passwordLength;
//            bool upperCase;
//            int upperCased;
//            bool specialChars;
//            int specialCharsd;
//            cout << "enter length of your password: ";
//            cin >> passwordLength;
//            cout << "Do you want upperCase in your password?"<< endl <<
//                 "1. YES " << endl <<
//                 "2. NO" << endl <<
//                 "Enter your choice:  ";
//            cin >> upperCased;
//            if(upperCased == 1){
//                upperCased = true;
//            }else{
//                upperCased = false;
//            }
//            cout << "Do you want special character in your password?"<< endl <<
//                 "1. YES " << endl <<
//                 "2. NO" << endl <<
//                 "Enter your choice:  ";
//            cin >> specialCharsd;
//            if(specialCharsd == 1){
//                specialChars = true;
//            }else{
//                specialChars = false;
//            }
//
//            passwordToAdd2 = PasswordManager::generatePassword(passwordLength,upperCase,specialCharsd);
//            int d6;
//            cout << "Do you want to add website and login?"<< endl <<
//                 "1. YES " << endl <<
//                 "2. NO" << endl <<
//                 "Enter your choice:  ";
//            cin >> d6;
//            switch(d6){
//                case 1:{
//                    string passwordWebsite;
//                    cout << "enter website: ";
//                    cin >> passwordWebsite;
//                    string passwordLogin;
//                    cout << "enter login: ";
//                    cin >> passwordLogin;
//                    passwordManager2.addPassword(
//                            Password(passwordName,
//                                     passwordToAdd2,
//                                     categories2.categoriesList[passwordCategory-1],
//                                     passwordWebsite,passwordLogin));
//                    break;
//                }
//                case 2:{
//                    passwordManager2.addPassword(
//                            Password(passwordName,
//                                     passwordToAdd2,
//                                     categories2.categoriesList[passwordCategory-1]));
//                    break;
//                }
//            }
//            passwordManager2.showFile();
//
//
//        }
//
//    }


    return 0;
}
