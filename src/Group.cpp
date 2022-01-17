//
// Created by nycuro on 10/30/21.
//

#include "../includes/Group.h"

// Implementarea constructorului de initializare
Group::Group(const std::string &name, const std::string &description, const std::vector<Rule> &rules, const std::vector<Post> &posts,
              const std::vector<User> &peopleJoined, const std::vector<User> &peopleRequestedToJoin) {
    std::cout << "[DEBUG] Apelare constructor Group.h" << std::endl;
    this->name = name;
    this->description = description;
    this->rules = rules;
    this->posts = posts;
    this->peopleJoined = peopleJoined;
    this->peopleRequestedToJoin = peopleRequestedToJoin;
}

// Implementarea destructorului
Group::~Group() {
    std::cout << "[DEBUG] Apelare destructor Group.h" << std::endl;
}

// Implementarea constructorului de copiere
Group::Group(const Group &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Group.h" << std::endl;
    this->name = copie.name;
    this->description = copie.description;
    this->rules = copie.rules;
    this->posts = copie.posts;
    this->peopleJoined = copie.peopleJoined;
    this->peopleRequestedToJoin = copie.peopleRequestedToJoin;
}

// Implementarea operatorului =
Group &Group::operator=(const Group &copie) {
    std::cout << "[DEBUG] Apelare operator = Group.h" << std::endl;
    this->name = copie.name;
    this->description = copie.description;
    this->rules = copie.rules;
    this->posts = copie.posts;
    this->peopleJoined = copie.peopleJoined;
    this->peopleRequestedToJoin = copie.peopleRequestedToJoin;
    return *this;
}

// Implementarea operatorului <<
std::ostream &operator<<(std::ostream &os, const Group &group) {
    std::cout << "[DEBUG] Apelare operator << Group.h" << std::endl;
    os << std::endl << group.name;
    os << std::endl << group.description;
    for (const auto &rule : group.rules) {
        os << std::endl << rule;
    }
    for (const auto &post : group.posts) {
        os << std::endl << post;
    }
    for (const auto &user : group.peopleJoined) {
        os << std::endl << user;
    }
    for (const auto &user : group.peopleRequestedToJoin) {
        os << std::endl << user;
    }
    return os;
}

// Getter pentru campul "name"
std::string &Group::getName() {
    return this->name;
}

// Setter pentru campul "name_"
void Group::setName(const std::string &name_) {
    this->name = name_;
}

void Group::handleGroup(const User &user) {
    std::cout << "TODO" << std::endl;
}
