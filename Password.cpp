//
// Created by Maciek on 27.05.2023.
//

#include "Password.h"

Password::Password(const std::string& name, const std::string& password, const std::string& category)
        : name(name), password(password), category(category), website(""), login("") {}

Password::Password(const std::string& name, const std::string& password, const std::string& category,
                   const std::string& website, const std::string& login)
        : name(name), password(password), category(category), website(website), login(login) {}

std::string Password::toString() const {
    std::string result = "Name: " + name + "   "
    +"Password: " + password + "   " +
    "Category: " + category + "   " +
    "Website: " + website + "   " +
    "Login: " + login;
    return result;
}

