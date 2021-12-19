//
// Created by Nicolae Marius Ghergu on 19.12.2021.
//

#include "../includes/WrongPasswordException.h"
#include <iostream>

WrongPasswordException::WrongPasswordException(const std::string &customMessage) : BaseException(customMessage) {
    std::cout << "[DEBUG] Apelare constructor WrongPasswordException.h" << std::endl;
}
