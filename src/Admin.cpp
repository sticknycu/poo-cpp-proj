//
// Created by Nicolae Marius Ghergu on 29.12.2021.
//

#include "../includes/Admin.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../includes/Utils.h"

template<typename T>
bool Admin<T>::isAdmin(const T &_identificator, const std::string type) const {
    std::ifstream file;
    std::string data;

    file.open("accounts.txt");

    while (std::getline(file, data)) {
        std::vector<std::string> wordsExploded = Utils::getInstance()->explodeString(data, '|');

        auto identificator = dynamic_cast<T>(_identificator);

        if (std::equal(type.begin(), type.end(), "username")) {
            User user;
            if (identificator == wordsExploded.at(0)) {
                user.setUsername(identificator);
                User::getUserInformationFromDatabase(user);
                if (wordsExploded.at(6) == "true") {
                    return true;
                }
            }
        } else if (std::equal(type.begin(), type.end(), "lastname")) {
            User user;
            if (identificator == wordsExploded.at(3)) {
                user.setLastname(identificator);
                User::getUserInformationFromDatabase(user);
                if (wordsExploded.at(6) == "true") {
                    return true;
                }
            }
        } else if (std::equal(type.begin(), type.end(), "firstname")) {
            User user;
            if (identificator == wordsExploded.at(4)) {
                user.setFirstname(identificator);
                User::getUserInformationFromDatabase(user);
                if (wordsExploded.at(6) == "true") {
                    return true;
                }
            }
        } else if (std::equal(type.begin(), type.end(), "cnp")) {
            User user;
            if (identificator == wordsExploded.at(4)) {
                user.setCNP(identificator);
                User::getUserInformationFromDatabase(user);
                if (wordsExploded.at(6) == "true") {
                    return true;
                }
            }
        }
    }

    file.close();

    return false;
}

template<typename T>
const std::vector<User>& Admin<T>::getAdmins() const {
    std::ifstream file;
    std::string data;

    file.open("accounts.txt");

    std::vector<User> listUser;

    while (std::getline(file, data)) {
        std::vector<std::string> wordsExploded = Utils::getInstance()->explodeString(data, '|');

        auto identificator = wordsExploded.at(6);

        if (identificator == "true") {
            auto username = wordsExploded.at(0);
            User user;
            user.setUsername(username);
            User::getUserInformationFromDatabase(user);
            listUser.push_back(user);
        }
    }

    file.close();

    return listUser;
}
