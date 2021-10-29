//
// Created by NicolaeMarius.Ghergu on 10/22/2021.
//
#pragma once

#ifndef UTILITYIT_GROUP_H
#define UTILITYIT_GROUP_H

#include <iostream>
#include "Rule.h"
#include "Post.h"
#include "User.h"

class Rule;
class Post;
class User;

class Group {

private:
    std::string description;
    std::vector<Rule> rules;
    std::vector<Post> posts;
    std::vector<User> peopleJoined;
    std::vector<User> peopleRequestedToJoin;

public:
    // constructor default
    Group() =default;

    // constructor de initializare
    Group(const std::string &description, const std::vector<Rule> &rules, const std::vector<Post> &posts,
          const std::vector<User> &peopleJoined, const std::vector<User> &peopleRequestedToJoin);

    // destructor
    ~Group();

    // constructor de copiere
    Group(const Group& copie);

    Group& operator=(const Group& copie);
};

#endif //UTILITYIT_GROUP_H