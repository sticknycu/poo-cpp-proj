//
// Created by Nicolae Marius Ghergu on 19.12.2021.
//

#ifndef UTILITYIT_BASEEXCEPTION_H
#define UTILITYIT_BASEEXCEPTION_H

#include <stdexcept>
#include <string>

class BaseException : public std::runtime_error {

private:

    std::string customMessage;

public:

    // constructor default
    BaseException() =default;

    // constructor de initializare
    BaseException(const std::string &customMessage);

    // destructor default
    ~BaseException() =default;

    const std::string &getCustomMessage();

    void setCustomMessage(const std::string &customMessage);
};


#endif //UTILITYIT_BASEEXCEPTION_H
