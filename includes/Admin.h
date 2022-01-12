//
// Created by Nicolae Marius Ghergu on 29.12.2021.
//
#pragma once

#ifndef UTILITYIT_ADMIN_H
#define UTILITYIT_ADMIN_H

#include <iostream>
#include "../includes/User.h"
#include <vector>

class User;

template <typename T>
class Admin {

private:
    T identificator;
public:

    Admin<T>() = default;

    Admin<T>(const Admin<T> &copie) = default;

    Admin<T>& operator=(const Admin<T> &copie);

    friend std::ostream& operator <<(std::ostream &os, const Admin<T> &admin);

    ~Admin<T>() = default;

    bool isAdmin(const T &identificator_, const std::string& type) const;

    std::vector<User> getAdmins();
};


#endif //UTILITYIT_ADMIN_H
