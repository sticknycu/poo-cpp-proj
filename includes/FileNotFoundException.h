//
// Created by Nicolae Marius Ghergu on 19.01.2022.
//

#ifndef UTILITYIT_FILENOTFOUNDEXCEPTION_H
#define UTILITYIT_FILENOTFOUNDEXCEPTION_H

#include "BaseException.h"

class BaseException;

class FileNotFoundException : public virtual BaseException {

public:
    // constructor default
    FileNotFoundException() = default;

    // constructor de initializare
    explicit FileNotFoundException(const std::string &customMessage);

    // destructor
    ~FileNotFoundException() override = default;

    std::string getCustomMessage() override;

    void setCustomMessage(const std::string &customMessage) override;
};


#endif //UTILITYIT_FILENOTFOUNDEXCEPTION_H
