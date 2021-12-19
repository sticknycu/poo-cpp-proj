//
// Created by Nicolae Marius Ghergu on 19.12.2021.
//

#ifndef UTILITYIT_WRONGPASSWORDEXCEPTION_H
#define UTILITYIT_WRONGPASSWORDEXCEPTION_H

#include "BaseException.h"

class WrongPasswordException : public BaseException {

public:
    // constructor default
    WrongPasswordException() =default;

    // constructor de initializare
    WrongPasswordException(const std::string &customMessage);

    // destructor
    ~WrongPasswordException() =default;
};


#endif //UTILITYIT_WRONGPASSWORDEXCEPTION_H
