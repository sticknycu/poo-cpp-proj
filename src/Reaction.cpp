//
// Created by nycuro on 10/30/21.
//

#include "../includes/Reaction.h"

// Implementarea constructorului de initializare
Reaction::Reaction(const long &id, std::shared_ptr<ReactionEnum> reactionType) {
    std::cout << "[DEBUG] Apelare constructor Reaction.h" << std::endl;
    this->id = id;
    this->reactionType = reactionType;
}

// Implementarea destructorului
Reaction::~Reaction() {
    std::cout << "[DEBUG] Apelare destructor Reaction.h" << std::endl;
}

// Implementarea constructorului de copiere
Reaction::Reaction(const Reaction &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Reaction.h" << std::endl;
    this->id = copie.id;
    this->reactionType = copie.reactionType;
}

// Implementarea operatorului =
Reaction &Reaction::operator=(const Reaction &copie) {
    std::cout << "[DEBUG] Apelare operator = Reaction.h" << std::endl;
    this->id = copie.id;
    this->reactionType = copie.reactionType;
    return *this;
}

// Implementarea operatorului <<
std::ostream &operator<<(std::ostream &os, const Reaction &reaction) {
    std::cout << "[DEBUG] Apelare operator << Reaction.h" << std::endl;
    os << std::endl << reaction.id;
    os << std::endl << reaction.reactionType;
    return os;
}

