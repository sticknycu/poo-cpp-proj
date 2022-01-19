//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//
#pragma once

#ifndef UTILITYIT_USER_H
#define UTILITYIT_USER_H

#include <iostream>
#include <utility>
#include <memory>
#include <vector>
#include "Group.h"

class Post;

class Group;

class Profile;

class User {

    friend class UserBuilder;

private:
    std::string username;
    std::string password;
    std::string firstname;
    std::string lastname;
    long cnp{};
    std::string sex;
    std::shared_ptr<Profile> userProfile;

public:
    // constructor default
    explicit User() = default;

    // constructor de initializare
    explicit User(const std::string &username, const std::string &password, const std::string &firstname,
                  const std::string &lastname,
                  const int &cnp, const std::string &sex, std::shared_ptr<Profile> &userProfile);

    // destructor
    virtual ~User();

    // constructor de copiere
    User(const User& copie);

    // operatorul =
    User& operator=(const User& copie);

    // operatorul <<
    friend std::ostream &operator<<(std::ostream &os, const User &user);

    std::string& getUsername();

    void setUsername(std::string &text);

    std::string& getPassword();

    void setPassword(std::string &text);

    std::string& getFirstname();

    void setFirstname(std::string &text);

    std::string& getLastname();

    void setLastname(std::string &text);

    long& getCNP();

    void setCNP(const long &text);

    std::string& getSex();

    void setSex(std::string &text);

    static bool checkUserAvailability(User &user);

    static User getUserInformationFromDatabase(User &user);

    // inregistrarea utilizatorului
    static void registerUser();

    // logarea utilizatorului
    static void loginUser();

    // Configurarea utilizatorului
    static User configureUser();

    // Handle register for users. Function for save user information to file.
    static void handleRegister(User &user);

    // Handle profile for users. Function for save profile information to file.
    static void handleProfile(Profile &profile);

    virtual void showInformationsAboutUser();
};

class UserBuilder {
    User user;

public:
    UserBuilder &username(const std::string &username_) {
        user.username = username_;
        return *this;
    }

    UserBuilder &password(const std::string &password_) {
        user.password = password_;
        return *this;
    }

    UserBuilder &firstname(const std::string &firstname_) {
        user.firstname = firstname_;
        return *this;
    }

    UserBuilder &lastname(const std::string &lastname_) {
        user.lastname = lastname_;
        return *this;
    }

    UserBuilder &sex(const std::string &sex_) {
        user.sex = sex_;
        return *this;
    }

    UserBuilder &cnp(const int &cnp_) {
        user.cnp = cnp_;
        return *this;
    }


    User build() {
        return user;
    }
};


class Profile : virtual public User {
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
    Profile() = default;

    // constructor de initializare
    Profile(const long &profileId, const std::vector<std::shared_ptr<Post>> &posts,
            const std::vector<std::shared_ptr<Group>> &groups, const std::vector<std::shared_ptr<User>> &followers,
            const std::vector<std::string> &studies, const std::vector<std::string> &livingPlaces);

    // destructor
    ~Profile() override;

    // constructor de copiere
    Profile(const Profile &copie);

    // operatorul =
    Profile &operator=(const Profile &copie);

    // operatorul <<
    friend std::ostream &operator<<(std::ostream &os, const Profile &profile);

    long &getId();

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

    void showInformationsAboutUser() override;
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


#endif //UTILITYIT_USER_H
