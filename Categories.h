//
// Created by Maciek on 01.06.2023.
//

#ifndef MENADZER_HASEL_CATEGORIES_H
#define MENADZER_HASEL_CATEGORIES_H

#include <iostream>
#include <vector>
#include <string>

class Categories {
public:
    Categories();
    std::vector <std::string> categoriesList;
    void addCategory(std::string);
    void deleteCategory(int categoryIndex);
    void showCategoryList();
};

#endif //MENADZER_HASEL_CATEGORIES_H
