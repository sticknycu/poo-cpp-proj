//
// Created by Nicolae Marius Ghergu on 19.01.2022.
//

#include "../includes/FileNotFoundException.h"
#include <iostream>

FileNotFoundException::FileNotFoundException(const std::string &customMessage)
        : runtime_error(customMessage), BaseException(
        getCustomMessage() + " " + customMessage) {
    std::cout << "[DEBUG] Apelare constructor FileNotFoundException.h" << std::endl;
}

std::string FileNotFoundException::getCustomMessage() {
    return "(FileNotFoundException): ";
}

void FileNotFoundException::setCustomMessage(const std::string &customMessage) {
    BaseException::setCustomMessage(customMessage);
}