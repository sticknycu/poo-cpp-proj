//
// Created by NicolaeMarius.Ghergu on 10/22/2021.
//
#pragma once

#ifndef UTILITYIT_PROFILE_H
#define UTILITYIT_PROFILE_H

#include <iostream>
#include <utility>
#include <vector>
#include "User.h"
#include "Group.h"

class Post;
class Group;
class User;

class Profile {
private:
    std::vector<Post*> posts;
    std::vector<Group*> groups;
    std::vector<User*> followers;
    std::vector<std::string> studies;
    std::vector<std::string> livingPlaces;
    /*std::vector<std::string> otherNames;
    std::vector<std::string> relationship;
    std::vector<std::string> family;
    std::vector<std::string> interests;
    std::vector<std::string> religion;
    std::vector<std::string> policyOrientation;
    std::vector<std::string> visits;
    std::vector<std::string> games;
    std::vector<std::string> pagesLiked;
    std::vector<User> usersFollowed;
    std::vector<std::string> events;
    long creationDate;
    std::vector<Group> groups;
    std::vector<User> followers;*/

public:
    // constructor default
    Profile() =default;

    // constructor de initializare
    Profile(const std::vector<Post*> &posts, const std::vector<Group*> &groups, const std::vector<User*> &followers,
         const std::vector<std::string> &studies, const std::vector<std::string> &livingPlaces);

    // destructor
    ~Profile();

    // constructor de copiere
    Profile(const Profile& copie);

    Profile& operator=(const Profile& copie);

};

#endif //UTILITYIT_PROFILE_H
