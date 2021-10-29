//
// Created by nycuro on 10/30/21.
//

#include "../includes/Group.h"

// Implementarea constructorului de initializare
Group::Group(const std::string &description, const std::vector<Rule> &rules, const std::vector<Post> &posts,
              const std::vector<User> &peopleJoined, const std::vector<User> &peopleRequestedToJoin) {
    std::cout << "[DEBUG] Apelare constructor Group.h";
    this->description = description;
    this->rules = rules;
    this->posts = posts;
    this->peopleJoined = peopleJoined;
    this->peopleRequestedToJoin = peopleRequestedToJoin;
}

// Implementarea destructorului
Group::~Group() {
    std::cout << "[DEBUG] Apelare destructor Group.h";
}

// Implementarea constructorului de copiere
Group::Group(const Group &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Group.h";
    this->description = copie.description;
    this->rules = copie.rules;
    this->posts = copie.posts;
    this->peopleJoined = copie.peopleJoined;
    this->peopleRequestedToJoin = copie.peopleRequestedToJoin;
}

// Implementarea operatorului =
Group &Group::operator=(const Group &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Group.h";
    this->description = copie.description;
    this->rules = copie.rules;
    this->posts = copie.posts;
    this->peopleJoined = copie.peopleJoined;
    this->peopleRequestedToJoin = copie.peopleRequestedToJoin;
    return *this;
}
