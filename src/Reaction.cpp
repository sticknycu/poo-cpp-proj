//
// Created by nycuro on 10/30/21.
//

#include "../includes/Reaction.h"

// Implementarea constructorului de initializare
Reaction::Reaction(const long &id, const std::string &name) {
    std::cout << "[DEBUG] Apelare constructor Reaction.h";
    this->id = id;
    this->name = name;
}

// Implementarea destructorului
Reaction::~Reaction() {
    std::cout << "[DEBUG] Apelare destructor Reaction.h";
}

// Implementarea constructorului de copiere
Reaction::Reaction(const Reaction &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Reaction.h";
    this->id = copie.id;
    this->name = copie.name;
}

// Implementarea operatorului =
Reaction &Reaction::operator=(const Reaction &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Reaction.h";
    this->id = copie.id;
    this->name = copie.name;
    return *this;
}

