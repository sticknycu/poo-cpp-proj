//
// Created by nycuro on 10/30/21.
//

#include "../includes/Utils.h"
#include <vector>
#include <iostream>
#include <sstream>

// Implementarea constructorului de initializare
Utils::Utils() {
    std::cout << "[DEBUG] Apelare constructor Utils.h" << std::endl;
}

// Implementarea destructorului
Utils::~Utils() {
    std::cout << "[DEBUG] Apelare destructor Utils.h" << std::endl;
}

// Implementarea constructorului de copiere
Utils::Utils(const Utils &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Utils.h" << std::endl;
}

// Implementarea operatorului =
Utils &Utils::operator=(const Utils &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Utils.h" << std::endl;
    return *this;
}

// Implementarea pentru a face split unui string.
std::vector<std::string> Utils::explodeString(std::string &text) {
    std::vector<std::string> words{};
    char delimiter = '|';

    std::istringstream sstream(text);
    std::string word;
    while (std::getline(sstream, word, delimiter)) {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }

    return words;
}