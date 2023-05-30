//
// Created by Maciek on 27.05.2023.
//

#ifndef MENADZER_HASEL_PASSWORD_H
#define MENADZER_HASEL_PASSWORD_H

#include <iostream>

class Password{
public:
    std::string name;
    std::string password;
    std::string category;
    std::string website;
    std::string login;


    Password(const std::string& name, const std::string& password, const std::string& category);
    Password(const std::string& name, const std::string& password, const std::string& category,
             const std::string& website, const std::string& login);

    [[nodiscard]] std::string toString() const;

};


#endif //MENADZER_HASEL_PASSWORD_H
