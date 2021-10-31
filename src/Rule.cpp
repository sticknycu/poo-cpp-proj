//
// Created by nycuro on 10/30/21.
//

#include "../includes/Rule.h"
#include "../includes/Utils.h"
#include <iostream>
#include <fstream>

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

long &Rule::getId() {
    return this->id;
}

void Rule::setId(const long &id) {
    this->id = id;
}

std::string &Rule::getText() {
    return this->text;
}

void Rule::setText(const std::string &text) {
    this->text = text;
}

void Rule::handleRule(const std::string &text) {
    std::ofstream file;
    std::ifstream readableOnly;
    std::string data;

    readableOnly.open("rules.txt", std::ios::in);

    int i = 1;
    while (getline(readableOnly, data)) {
        i++;
    }

    std::string id = std::to_string(i);

    data = id.append("|").append(text);

    file.open("rules.txt", std::ios::out | std::ios::app);

    file << std::endl << data;

    readableOnly.close();
    file.close();
}

void Rule::createRule(User &user) {
    std::cout << "Pentru a crea o regula, te rugam sa introduci textul ce descrie regula:" << std::endl;
    std::string input;
    input = Utils::handleInput(input);
    handleRule(input);
    Utils::navigatePlatform(user);
}
