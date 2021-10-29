//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//
#pragma once

#ifndef UTILITYIT_COMMENT_H
#define UTILITYIT_COMMENT_H

#include <iostream>
#include "User.h"

class User;

class Comment {
private:
    long id;
    User *createdBy;
    long creationDate;
    std::string text;

public:

    // constructor default
    Comment() =default;

    // constructor de initializare
    Comment(const long &id, User *createdBy, const long &creationDate, const std::string &text);

    // destructor
    ~Comment();

    // constructor de copiere
    Comment(const Comment& copie);

    Comment& operator=(const Comment& copie);
};

#endif //UTILITYIT_COMMENT_H
