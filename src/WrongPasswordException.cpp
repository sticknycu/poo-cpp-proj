//
// Created by Nicolae Marius Ghergu on 19.12.2021.
//

#include "../includes/WrongPasswordException.h"
#include <iostream>

WrongPasswordException::WrongPasswordException(const std::string &customMessage)
        : std::runtime_error(customMessage), BaseException(getCustomMessage() + " " + customMessage) {
    std::cout << "[DEBUG] Apelare constructor WrongPasswordException.h" << std::endl;
}

std::string WrongPasswordException::getCustomMessage() {
    return "(WrongPasswordException): ";
}

void WrongPasswordException::setCustomMessage(const std::string &customMessage) {
    BaseException::setCustomMessage(customMessage);
}
