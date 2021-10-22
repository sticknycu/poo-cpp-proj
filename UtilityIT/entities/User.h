//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//

#ifndef UTILITYIT_USER_H
#define UTILITYIT_USER_H

#include <iostream>

class User {
private:
    std::string firstName;
    std::string lastName;
    int cnp;
    std::string email;
    std::string sex;
    long birthdayDate;

public:

    User() {
    }

    std::string getFirstName() {
        this->firstName;
    }

    void setFirstName(std::string firstName) {
        this->firstName = firstName;
    }

    std::string getLastName() {
        return this->lastName;
    }

    void setLastName(std::string lastName) {
        this->lastName = lastName;
    }

    int getCnp() {
        return this->cnp;
    }

    void setCnp(int cnp) {
        this->cnp = cnp;
    }
};


#endif //UTILITYIT_USER_H
