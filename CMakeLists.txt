cmake_minimum_required(VERSION 3.24)
project(menadzer_hasel)

set(CMAKE_CXX_STANDARD 23)

add_executable(menadzer_hasel main.cpp Menu.cpp Menu.h Password.cpp Password.h PasswordManager.cpp PasswordManager.h Categories.cpp Categories.h)
