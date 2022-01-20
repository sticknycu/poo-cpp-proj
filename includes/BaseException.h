//
// Created by Nicolae Marius Ghergu on 19.12.2021.
//

#ifndef UTILITYIT_BASEEXCEPTION_H
#define UTILITYIT_BASEEXCEPTION_H

#include <stdexcept>
#include <string>

class BaseException : virtual public std::runtime_error {

private:

    std::string customMessage;

public:

    // constructor default
    BaseException() = default;

    // constructor de initializare
    explicit BaseException(const std::string &customMessage);

    // destructor default
    ~BaseException() override = default;

    virtual std::string getCustomMessage() = 0;

    virtual void setCustomMessage(const std::string &customMessage_) = 0;
};


#endif //UTILITYIT_BASEEXCEPTION_H
