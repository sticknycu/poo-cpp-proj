//
// Created by nycuro on 10/30/21.
//

#include "../includes/Rule.h"

// Implementarea constructorului de initializare
Rule::Rule(const long &id, const std::string &text) {
    std::cout << "[DEBUG] Apelare constructor Rule.h" << std::endl;
    this->id = id;
    this->text = text;
}

// Implementarea destructorului
Rule::~Rule() {
    std::cout << "[DEBUG] Apelare destructor Rule.h" << std::endl;
}

// Implementarea constructorului de copiere
Rule::Rule(const Rule &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Rule.h" << std::endl;
    this->id = copie.id;
    this->text = copie.text;
}

// Implementarea operatorului =
Rule &Rule::operator=(const Rule &copie) {
    std::cout << "[DEBUG] Apelare operator = Rule.h" << std::endl;
    this->id = copie.id;
    this->text = copie.text;
    return *this;
}

// Implementarea operatorului <<
std::ostream &operator<<(std::ostream &os, const Rule &rule) {
    std::cout << "[DEBUG] Apelare operator << Rule.h" << std::endl;
    os << std::endl << rule.id;
    os << std::endl << rule.text;
    return os;
}

