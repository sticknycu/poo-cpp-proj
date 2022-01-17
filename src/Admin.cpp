//
// Created by Nicolae Marius Ghergu on 29.12.2021.
//

#include <iostream>

template<typename T>
bool Admin<T>::isAdmin(const T &identificator_, const std::string &type) const {
    std::ifstream file;
    std::string data;

    file.open("accounts.txt");

    while (std::getline(file, data)) {
        std::vector<std::string> wordsExploded = Utils::splitString(data, '|');

        if (std::equal(type.begin(), type.end(), "username")) {
            User user;
            if (identificator_ == wordsExploded.at(0)) {
                user.setUsername(identificator_);
                User::getUserInformationFromDatabase(user);
                if (wordsExploded.at(6) == "true") {
                    return true;
                }
            }
        } else if (std::equal(type.begin(), type.end(), "lastname")) {
            User user;
            if (identificator_ == wordsExploded.at(3)) {
                user.setLastname(identificator_);
                User::getUserInformationFromDatabase(user);
                if (wordsExploded.at(6) == "true") {
                    return true;
                }
            }
        } else if (std::equal(type.begin(), type.end(), "firstname")) {
            User user;
            if (identificator_ == wordsExploded.at(4)) {
                user.setFirstname(identificator_);
                User::getUserInformationFromDatabase(user);
                if (wordsExploded.at(6) == "true") {
                    return true;
                }
            }
        } else if (std::equal(type.begin(), type.end(), "cnp")) {
            User user;
            if (identificator_ == wordsExploded.at(4)) {
                user.setCNP(identificator_);
                User::getUserInformationFromDatabase(user);
                if (wordsExploded.at(6) == "true") {
                    return true;
                }
            }
        }
    }

    return false;
}

template<typename T>
std::vector<User> Admin<T>::getAdmins() {
    std::ifstream file;
    std::string data;

    file.open("accounts.txt");

    std::vector<User> listUser;

    while (std::getline(file, data)) {
        std::vector<std::string> wordsExploded = Utils::splitString(data, '|');

        auto identificator = wordsExploded.at(6);

        if (identificator == "true") {
            auto username = wordsExploded.at(0);
            User user;
            user.setUsername(username);
            User::getUserInformationFromDatabase(user);
            listUser.push_back(user);
        }
    }

    return listUser;
}

template<typename T>
Admin<T> &Admin<T>::operator=(const Admin<T> &copie) {
    std::cout << "[DEBUG] Apelare operator = Admin.h" << std::endl;
    this->identificator = copie.identificator;
    return *this;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Admin<T> &admin) {
    std::cout << "[DEBUG] Apelare operator << Comment.h" << std::endl;
    os << std::endl << admin.identificator;
    return os;
}
