//
// Created by Nicolae Marius Ghergu on 19.12.2021.
//

#include "../includes/BaseException.h"
#include <iostream>

BaseException::BaseException(const std::string &customMessage) : runtime_error("BasicException error: " + customMessage) {
    std::cout << "[DEBUG] Apelare constructor BaseException.h" << std::endl;
}

const std::string &BaseException::getCustomMessage() {
    return this->customMessage;
}

void BaseException::setCustomMessage(const std::string &customMessage) {
    this->customMessage = customMessage;
}
