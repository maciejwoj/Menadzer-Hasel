//
// Created by Maciek on 27.05.2023.
//

#include "Menu.h"

Menu::Menu() {

}

void Menu::choice() {
    std::cout << "~~~~~~~~~~s27578~~~~~~~~~~\n" <<
    "1. Option 1\n" <<
    "2. Option 2\n" <<
    "3. Option 3\n" <<
    "4. Exit\n" <<
    "~~~~~~~~~~s27578~~~~~~~~~~\n";


    std::cout << "Enter your choice: ";
    int ch;
    std::cin >> ch;



    switch (ch) {
        case 1:
            std::cout << "You chose Option 1.\n";
            // Dodaj kod dla akcji związanej z opcją 1
            break;
        case 2:
            std::cout << "You chose Option 2.\n";
            // Dodaj kod dla akcji związanej z opcją 2
            break;
        case 3:
            std::cout << "You chose Option 3.\n";
            // Dodaj kod dla akcji związanej z opcją 3
            break;
        case 4:
            std::cout << "Exiting the program.\n";
            // Dodaj kod dla akcji związanej z opcją "Exit"
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
    }
}