//
// Created by Nicolae Marius Ghergu on 29.12.2021.
//
#pragma once

#ifndef UTILITYIT_ADMIN_H
#define UTILITYIT_ADMIN_H

#include <iostream>

class User;

template <typename T>
class Admin {

private:
    T identificator;

    static Admin<T>* instance;

    Admin<T>() = default;

public:

    static Admin<T>* getInstance() {
        if (instance == nullptr) {
            instance = new Admin<T>();
        }
        return instance;
    }

    Admin<T>(const std::shared_ptr<T> &user) = delete;

    Admin<T>(const T &copie) = delete;

    Admin<T>& operator=(const T &copie) = delete;

    friend std::ostream& operator <<(const std::ostream &os, const T &admin) = delete;

    ~Admin<T>() = default;

    bool isAdmin(const T &identificator, const std::string type) const;

    const std::vector<User>& getAdmins() const;
};


#endif //UTILITYIT_ADMIN_H
