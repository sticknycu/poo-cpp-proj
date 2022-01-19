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
#include <memory>

class Post;
class Group;
class User;

class Profile {
    friend class ProfileBuilder;

private:
    long profileId{};
    std::vector<std::shared_ptr<Post>> posts;
    std::vector<std::shared_ptr<Group>> groups;
    std::vector<std::shared_ptr<User>> followers;
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
    Profile(const long &profileId, const std::vector<std::shared_ptr<Post>> &posts, const std::vector<std::shared_ptr<Group>> &groups, const std::vector<std::shared_ptr<User>> &followers,
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

    std::vector<std::shared_ptr<Post>> getPosts();

    void setPosts(std::vector<std::shared_ptr<Post>> &posts_);

    std::vector<std::shared_ptr<Group>> getGroups();

    void setGroups(const std::vector<std::shared_ptr<Group>> &groups_);

    std::vector<std::shared_ptr<User>> &getFollowers();

    void setFollowers(const std::vector<std::shared_ptr<User>> &followers_);

    std::vector<std::string> &getStudies();

    void setStudies(const std::vector<std::string> &studies_);

    std::vector<std::string> &getLivingPlaces();

    void setLivingPlaces(const std::vector<std::string> &livingPlaces_);

    // Handle data to be removed if that exists already in file when profile is updated
    void manageExistenceProfileData();

    // Configurarea profilului.
    static Profile configureProfile(User &user);
};

class ProfileBuilder {

private:
    Profile profile;

public:
    ProfileBuilder() = default;

    ProfileBuilder &profileId(long &profileId_) {
        profile.profileId = profileId_;
        return *this;
    }

    ProfileBuilder &posts(std::vector<std::shared_ptr<Post>> &posts_) {
        profile.posts = posts_;
        return *this;
    }

    ProfileBuilder &groups(std::vector<std::shared_ptr<Group>> &groups_) {
        profile.groups = groups_;
        return *this;
    }

    ProfileBuilder &followers(std::vector<std::shared_ptr<User>> &followers_) {
        profile.followers = followers_;
        return *this;
    }

    ProfileBuilder &studies(std::vector<std::string> &studies_) {
        profile.studies = studies_;
        return *this;
    }

    ProfileBuilder &livingPlaces(std::vector<std::string> &livingPlaces_) {
        profile.livingPlaces = livingPlaces_;
        return *this;
    }

    Profile build() {
        return profile;
    }
};

#endif //UTILITYIT_PROFILE_H
