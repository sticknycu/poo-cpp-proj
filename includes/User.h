//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//

#ifndef UTILITYIT_USER_H
#define UTILITYIT_USER_H

#include <iostream>
#include <utility>
#include "Profile.h"

class User {

private:
    std::string email;
    std::string password;
    std::string firstname;
    std::string lastname;
    int cnp;
    std::string sex;
    long birthdayDate;
    Profile userProfile;

public:
    // constructor default
    User() =default;

    // constructor de initializare
    User(const std::string &email, const std::string &password, const std::string &firstname, const std::string &lastname,
         const int &cnp, const std::string &sex, const long &birthdayDate, const Profile &userProfile);

    // destructor
    ~User();

    // constructor de copiere
    User(const User& copie);

    User& operator=(const User& copie);
};


#endif //UTILITYIT_USER_H
