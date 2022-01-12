//
// Created by nycuro on 10/30/21.
//

#include "../includes/Utils.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "../includes/WrongPasswordException.h"
#include "../includes/Admin.h"

class WrongPasswordException;
template<typename T>
class Admin;

// Implementarea pentru a face split unui string.
std::vector<std::string> Utils::splitString(std::string &text, char delimiter) {
    std::vector<std::string> words{};

    std::istringstream sstream(text);
    std::string word;
    while (std::getline(sstream, word, delimiter)) {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }

    return words;
}

const std::string& Utils::handleInput(std::string &text) {
    for(;;) {
        getline(std::cin, text);

        if (!text.empty()) {
            break;
        } else if (std::cin.fail()) {
            std::cin.clear();
        }
    }
    return text;
}

long Utils::getCurrentTime() {
    return static_cast<long> (time(nullptr));;
}
