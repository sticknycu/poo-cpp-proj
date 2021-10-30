//
// Created by nycuro on 10/30/21.
//

#include "../includes/User.h"
#include <fstream>
#include "../includes/Utils.h"

// Implementarea constructorului de initializare
User::User(const std::string &username, const std::string &password, const std::string &firstname, const std::string &lastname,
           const int &cnp, const std::string &sex, Profile* &userProfile) {
    std::cout << "[DEBUG] Apelare constructor User.h" << std::endl;
    this->username = username;
    this->password = password;
    this->firstname = firstname;
    this->lastname = lastname;
    this->cnp = cnp;
    this->sex = sex;
    this->userProfile = userProfile;
}

// Implementarea destructorului
User::~User() {
    std::cout << "[DEBUG] Apelare destructor User.h" << std::endl;
}

// Implementarea constructorului de copiere
User::User(const User &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere User.h" << std::endl;
    this->username = copie.username;
    this->password = copie.password;
    this->firstname = copie.firstname;
    this->lastname = copie.lastname;
    this->cnp = copie.cnp;
    this->sex = copie.sex;
    this->userProfile = copie.userProfile;
}

// Implementarea operatorului =
User &User::operator=(const User &copie) {
    std::cout << "[DEBUG] Apelare operator = User.h" << std::endl;
    this->username = copie.username;
    this->password = copie.password;
    this->firstname = copie.firstname;
    this->lastname = copie.lastname;
    this->cnp = copie.cnp;
    this->sex = copie.sex;
    this->userProfile = copie.userProfile;
    return *this;
}

// Implementarea operatorului <<
std::ostream &operator<<(std::ostream &os, const User &user) {
    std::cout << "[DEBUG] Apelare operator << User.h" << std::endl;
    os << std::endl << user.username;
    os << std::endl << user.password;
    os << std::endl << user.firstname;
    os << std::endl << user.lastname;
    os << std::endl << user.cnp;
    os << std::endl << user.sex;

    return os;
}

// Getter pentru campul "username"
std::string& User::getUsername() {
    return this->username;
}

// Setter pentru campul "username"
void User::setUsername(std::string &text) {
    this->username = text;
}

// Getter pentru campul "password"
std::string& User::getPassword() {
    return this->password;
}

// Setter pentru campul "password"
void User::setPassword(std::string &text) {
    this->password = text;
}

// Getter pentru campul "firstname"
std::string& User::getFirstname() {
    return this->firstname;
}

// Setter pentru campul "firstname"
void User::setFirstname(std::string &text) {
    this->firstname = text;
}

// Getter pentru campul "lastname"
std::string& User::getLastname() {
    return this->lastname;
}

// Setter pentru campul "lastname"
void User::setLastname(std::string &text) {
    this->lastname = text;
}

// Getter pentru campul "cnp"
long& User::getCNP() {
    return this->cnp;
}

// Setter pentru campul "cnp"
void User::setCNP(const long &text) {
    this->cnp = text;
}

// Getter pentru campul "sex"
std::string& User::getSex() {
    return this->sex;
}

// Setter pentru campul "sex"
void User::setSex(std::string &text) {
    this->sex = text;
}

// Implementarea de la userAvailability (verific daca user-ul exista)
bool User::checkUserAvailability(User &user) {
    std::ifstream file;
    std::string data;

    file.open("accounts.txt");

    while (std::getline(file, data)) {
        std::vector<std::string> wordsExploded = Utils::explodeString(data);
        for (const auto &word : wordsExploded) {
            if (user.getUsername() == word) {
                file.close();
                return true;
            }
        }
    }

    file.close();

    return false;
}

User User::getUserInformationFromDatabase(User &user) {
    std::ifstream file;
    std::string data;

    file.open("accounts.txt");

    while (std::getline(file, data)) {
        std::vector<std::string> wordsExploded = Utils::explodeString(data);
        if (user.getUsername() == wordsExploded.at(0)) {
            user.setPassword(wordsExploded.at(1));
            user.setFirstname(wordsExploded.at(2));
            user.setLastname(wordsExploded.at(3));
            user.setCNP(std::stol(wordsExploded.at(4)));
            user.setSex(wordsExploded.at(5));
        }
    }

    file.close();

    return user;
}

