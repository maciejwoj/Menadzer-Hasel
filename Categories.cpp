//
// Created by Maciek on 01.06.2023.
//

#include "Categories.h"

using namespace std;
Categories::Categories() {

}

void Categories::addCategory(string category) {
    bool isAlreadyUsed = false;
    for(int i = 0; i < categoriesList.size(); i++){
        if(categoriesList[i] == category){
            isAlreadyUsed = true;
        }
    }
    if(!isAlreadyUsed){
        categoriesList.push_back(category);
    }
}

void Categories::deleteCategory(int categoryIndex) {
    categoriesList.erase(categoriesList.begin() + categoryIndex);
}

void Categories::showCategoryList() {
    for(int i = 0; i < categoriesList.size(); i++){
        cout<<i+1 << ". " << categoriesList[i] << endl;
    }
}




