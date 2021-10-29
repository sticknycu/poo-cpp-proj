//
// Created by nycuro on 10/30/21.
//

#include "../includes/Profile.h"

// Implementarea constructorului de initializare
Profile::Profile(const std::vector<Post*> &posts, const std::vector<Group*> &groups, const std::vector<User*> &followers,
                 const std::vector<std::string> &studies, const std::vector<std::string> &livingPlaces) {
    std::cout << "[DEBUG] Apelare constructor Profile.h";
    this->posts = posts;
    this->groups = groups;
    this->followers = followers;
    this->studies = studies;
    this->livingPlaces = livingPlaces;
}

// Implementarea destructorului
Profile::~Profile() {
    std::cout << "[DEBUG] Apelare destructor Profile.h";
}

// Implementarea constructorului de copiere
Profile::Profile(const Profile &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Profile.h";
    this->posts = copie.posts;
    this->groups = copie.groups;
    this->followers = copie.followers;
    this->studies = copie.studies;
    this->livingPlaces = copie.livingPlaces;
}

// Implementarea operatorului =
Profile &Profile::operator=(const Profile &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Profile.h";
    this->posts = copie.posts;
    this->groups = copie.groups;
    this->followers = copie.followers;
    this->studies = copie.studies;
    this->livingPlaces = copie.livingPlaces;
    return *this;
}
