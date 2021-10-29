//
// Created by nycuro on 10/30/21.
//

#include "../includes/User.h"

// Implementarea constructorului de initializare
User::User(const std::string &email, const std::string &password, const std::string &firstname, const std::string &lastname,
           const int &cnp, const std::string &sex, const long &birthdayDate, Profile* &userProfile) {
    std::cout << "[DEBUG] Apelare constructor User.h";
    this->email = email;
    this->password = password;
    this->firstname = firstname;
    this->lastname = lastname;
    this->cnp = cnp;
    this->sex = sex;
    this->birthdayDate = birthdayDate;
    this->userProfile = userProfile;
}

// Implementarea destructorului
User::~User() {
    std::cout << "[DEBUG] Apelare destructor User.h";
}

// Implementarea constructorului de copiere
User::User(const User &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere User.h";
    this->email = copie.email;
    this->password = copie.password;
    this->firstname = copie.firstname;
    this->lastname = copie.lastname;
    this->cnp = copie.cnp;
    this->sex = copie.sex;
    this->birthdayDate = copie.birthdayDate;
    this->userProfile = copie.userProfile;
}

// Implementarea operatorului =
User &User::operator=(const User &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere User.h";
    this->email = copie.email;
    this->password = copie.password;
    this->firstname = copie.firstname;
    this->lastname = copie.lastname;
    this->cnp = copie.cnp;
    this->sex = copie.sex;
    this->birthdayDate = copie.birthdayDate;
    this->userProfile = copie.userProfile;
    return *this;
}

