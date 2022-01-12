//
// Created by nycuro on 10/30/21.
//

#include <fstream>
#include "../includes/Profile.h"
#include "../includes/Utils.h"

class Utils;

// Implementarea constructorului de initializare
Profile::Profile(const long &profileId, const std::vector<std::shared_ptr<Post>> &posts, const std::vector<std::shared_ptr<Group>> &groups, const std::vector<std::shared_ptr<User>> &followers,
                 const std::vector<std::string> &studies, const std::vector<std::string> &livingPlaces) {
    std::cout << "[DEBUG] Apelare constructor Profile.h" << std::endl;
    this->profileId = profileId;
    this->posts = posts;
    this->groups = groups;
    this->followers = followers;
    this->studies = studies;
    this->livingPlaces = livingPlaces;
}

// Implementarea destructorului
Profile::~Profile() {
    std::cout << "[DEBUG] Apelare destructor Profile.h" << std::endl;
}

// Implementarea constructorului de copiere
Profile::Profile(const Profile &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Profile.h" << std::endl;
    this->profileId = copie.profileId;
    this->posts = copie.posts;
    this->groups = copie.groups;
    this->followers = copie.followers;
    this->studies = copie.studies;
    this->livingPlaces = copie.livingPlaces;
}

// Implementarea operatorului =
Profile &Profile::operator=(const Profile &copie) {
    std::cout << "[DEBUG] Apelare operator = Profile.h" << std::endl;
    this->profileId = copie.profileId;
    this->posts = copie.posts;
    this->groups = copie.groups;
    this->followers = copie.followers;
    this->studies = copie.studies;
    this->livingPlaces = copie.livingPlaces;
    return *this;
}

// Implementarea operatorului <<
std::ostream &operator<<(std::ostream &os, const Profile &profile) {
    std::cout << "[DEBUG] Apelare operator << Profile.h" << std::endl;
    os << std::endl << profile.profileId;
    for (const auto &post : profile.posts) {
        os << std::endl << post;
    }
    for (const auto &group : profile.groups) {
        os << std::endl << group;
    }
    for (const auto &follower : profile.followers) {
        os << std::endl << follower;
    }
    for (const auto &study : profile.studies) {
        os << std::endl << study;
    }
    for (const auto &livingPlace : profile.livingPlaces) {
        os << std::endl << livingPlace;
    }
    return os;
}

// Getter pentru campul "profileId"
long& Profile::getId() {
    return this->profileId;
}

// Setter pentru campul "profileId"
void Profile::setId(const long &id) {
    this->profileId = id;
}

// Getter pentru campul "posts"
std::vector<std::shared_ptr<Post>> Profile::getPosts() {
    return this->posts;
}

// Setter pentru campul "posts
void Profile::setPosts(std::vector<std::shared_ptr<Post>> &posts) {
    this->posts = posts;
}

// Getter pentru campul "groups"
std::vector<std::shared_ptr<Group>> Profile::getGroups() {
    return this->groups;
}

// Setter pentru campul "groups"
void Profile::setGroups(const std::vector<std::shared_ptr<Group>> &groups) {
    this->groups = groups;
}

// Getter pentru campul "followers"
std::vector<std::shared_ptr<User>> &Profile::getFollowers() {
    return this->followers;
}

// Setter pentru campul "followers"
void Profile::setFollowers(const std::vector<std::shared_ptr<User>> &followers) {
    this->followers = followers;
}

// Getter pentru campul "studies"
std::vector<std::string> &Profile::getStudies() {
    return this->studies;
}

// Setter pentru campul "studies"
void Profile::setStudies(const std::vector<std::string> &studies) {
    this->studies = studies;
}

// Getter pentru campul "livingPlaces"
std::vector<std::string> &Profile::getLivingPlaces() {
    return this->livingPlaces;
}

// Setter pentru campul "livingPlaces"
void Profile::setLivingPlaces(const std::vector<std::string> &livingPlaces) {
    this->livingPlaces = livingPlaces;
}

void Profile::manageExistenceProfileData(Profile &profile) {
    std::ifstream oldFile;
    std::ofstream newFile;
    std::string data;

    oldFile.open("profiles.txt");

    bool exist = false;
    while (std::getline(oldFile, data)) {
        std::vector<std::string> wordsExploded = Utils::splitString(data, '|');
        if (wordsExploded.at(0) == std::to_string(profile.getId())) {
            exist = true;
            break;
        }
    }


    data = "";
    if (exist) {
        newFile.open("profilesNew.txt", std::ios::out | std::ios::app);
        while (std::getline(oldFile, data)) {
            std::vector<std::string> wordsExploded = Utils::splitString(data, '|');
            if (wordsExploded.at(0) != std::to_string(profile.getId())) {
                newFile << data << std::endl;
            }
        }
    }

    remove("profiles.txt");
    rename("profilesNew.txt", "profiles.txt");
}

const Profile Profile::configureProfile(User &user) {
    std::cout << "Ne bucuram ca iti doresti sa iti configurezi profilul. De aceea, te rugam sa ne spui urmatoarele informatii:" << std::endl;
    Profile profile;
    profile.setId(user.getCNP());
    std::cout << "Ce studiezi si ce studii ai avut pana acum? Te rugam sa le notezi cu virgula, fara spatii." << std::endl;

    std::string valuableString;
    valuableString = Utils::handleInput(valuableString);

    std::vector<std::string> studies = Utils::splitString(valuableString, ',');
    profile.setStudies(studies);
    std::cout << "Unde locuiesti si unde ai locuit pana acum? Te rugam sa le notezi cu virgula, fara spatii." << std::endl;

    valuableString = Utils::handleInput(valuableString);
    std::vector<std::string> livingPlaces = Utils::splitString(valuableString, ',');
    profile.setLivingPlaces(livingPlaces);

    User::handleProfile(profile);

    std::cout << "Ai configurat profilul cu succes!" << std::endl;
    return profile;
}