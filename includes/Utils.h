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

private:

    Utils() = default;

    static Utils* instance;

public:

    Utils(const Utils&) = delete;

    // operatorul =
    Utils& operator=(const Utils&) = delete;

    static Utils* getInstance() {
        if (instance == nullptr) {
            instance = new Utils();
        }
        return instance;
    }

    // Implementarea pentru a face split al unui string.
    std::vector<std::string> explodeString(std::string &text, char delimiter);

    // inregistrarea utilizatorului
    void registerUser();

    // logarea utilizatorului
    void loginUser();

    // Configurarea utilizatorului
    User configurateUser(User &user);

    // Configurarea profilului.
    Profile configureProfile(User &user);

    // Navigarea pe plaforma
    void navigatePlatform(User &user);

    // Handle register for users. Function for save user information to file.
    void handleRegister(User &user);

    // Handle profile for users. Function for save profile information to file.
    void handleProfile(Profile &profile);

    // Handle string when is shit and don't want to
    std::string handleInput(std::string &text);

    // Handle data to be removed if that exists already in file when profile is updated
    void manageExistanceProfileData(Profile &profile);

    static long getCurrentTime();
};

#endif //UTILITYIT_UTILS_H
