//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//
#pragma once

#ifndef UTILITYIT_USER_H
#define UTILITYIT_USER_H

#include <iostream>
#include <utility>
#include "Profile.h"
#include <memory>

class Profile;

class User {

private:
    std::string username;
    std::string password;
    std::string firstname;
    std::string lastname;
    long cnp{};
    std::string sex;
    std::shared_ptr<Profile> userProfile;

public:
    // constructor default
    User() =default;

    // constructor de initializare
    User(const std::string &username, const std::string &password, const std::string &firstname, const std::string &lastname,
         const int &cnp, const std::string &sex, std::shared_ptr<Profile> &userProfile);

    // destructor
    ~User();

    // constructor de copiere
    User(const User& copie);

    // operatorul =
    User& operator=(const User& copie);

    // operatorul <<
    friend std::ostream &operator<<(std::ostream &os, const User &user);

    std::string& getUsername();

    void setUsername(std::string &text);

    std::string& getPassword();

    void setPassword(std::string &text);

    std::string& getFirstname();

    void setFirstname(std::string &text);

    std::string& getLastname();

    void setLastname(std::string &text);

    long& getCNP();

    void setCNP(const long &text);

    std::string& getSex();

    void setSex(std::string &text);

    static bool checkUserAvailability(User &user);

    static User getUserInformationFromDatabase(User &user);

    // inregistrarea utilizatorului
    static void registerUser();

    // logarea utilizatorului
    static void loginUser();

    // Configurarea utilizatorului
    static const User& configureUser(User &user);

    // Handle register for users. Function for save user information to file.
    static void handleRegister(User &user);

    // Handle profile for users. Function for save profile information to file.
    static void handleProfile(Profile &profile);
};


#endif //UTILITYIT_USER_H
