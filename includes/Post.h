//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//
#pragma once

#ifndef UTILITYIT_POST_H
#define UTILITYIT_POST_H

#include <iostream>
#include "Comment.h"
#include "ReactionEnum.h"
#include <vector>

enum class ReactionEnum;
class Comment;
class User;

class Post {
private:
    long id;
    std::string description;
    std::vector<ReactionEnum*> reactions;
    std::vector<Comment*> comments;
    User *createdBy;
    long creationDate;

public:
    // constructor default
    Post() =default;

    // constructor de initializare
    Post(const long &id, const std::string &description, const std::vector<ReactionEnum*> &reactions,
         const std::vector<Comment*> &comments, User* createdBy, const long &creationDate);

    // destructor
    ~Post();

    // constructor de copiere
    Post(const Post& copie);

    // operatorul =
    Post& operator=(const Post& copie);

    // operatorul <<
    friend std::ostream &operator<<(std::ostream &os, const Post &post);
};


#endif //UTILITYIT_POST_H
