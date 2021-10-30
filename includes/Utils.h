//
// Created by nycuro on 10/30/21.
//
#pragma once

#ifndef UTILITYIT_UTILS_H
#define UTILITYIT_UTILS_H

#include <iostream>
#include <vector>
#include "../includes/User.h"

class Utils {

public:

    // constructor default fara parametrii
    Utils();

    // destructor
    ~Utils();

    // constructor de copiere
    Utils(const Utils& copie);

    // operatorul =
    Utils& operator=(const Utils& copie);

    // Implementarea pentru a face split al unui string.
    static std::vector<std::string> explodeString(std::string &text, char delimiter);

    // inregistrarea utilizatorului
    static void registerUser();

    // logarea utilizatorului
    static void loginUser();

    // Configurarea utilizatorului
    static User configurateUser(User &user);

    // Configurarea profilului.
    static Profile configureProfile(User &user);

    // Navigarea pe plaforma
    static void navigatePlatform(User &user);

    // Handle register for users. Function for save user information to file.
    static void handleRegister(User &user);

    // Handle string when is shit and don't want to
    static std::string handleInput(std::string &text);


};

#endif //UTILITYIT_UTILS_H
