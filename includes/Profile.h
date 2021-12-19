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
    long profileId;
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
    Profile(const long &profileId, const std::vector<Post*> &posts, const std::vector<Group*> &groups, const std::vector<User*> &followers,
         const std::vector<std::string> &studies, const std::vector<std::string> &livingPlaces);

    // destructor
    ~Profile();

    // constructor de copiere
    Profile(const Profile& copie);

    // operatorul =
    Profile& operator=(const Profile& copie);

    // operatorul <<
    friend std::ostream &operator<<(std::ostream &os, const Profile &profile);

    long& getId();

    void setId(const long &id);

    std::vector<Post*> getPosts();

    void setPosts(std::vector<Post*> &posts);

    std::vector<Group *> getGroups();

    void setGroups(const std::vector<Group*> &groups);

    std::vector<User*> &getFollowers();

    void setFollowers(const std::vector<User*> &followers);

    std::vector<std::string> &getStudies();

    void setStudies(const std::vector<std::string> &studies);

    std::vector<std::string> &getLivingPlaces();

    void setLivingPlaces(const std::vector<std::string> &livingPlaces);

};

#endif //UTILITYIT_PROFILE_H
