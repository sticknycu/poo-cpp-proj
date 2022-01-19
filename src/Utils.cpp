//
// Created by nycuro on 10/30/21.
//

#include "../includes/Utils.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include "../includes/WrongPasswordException.h"
#include "../includes/Admin.h"

class WrongPasswordException;
template<typename T>
class Admin;

// Implementarea pentru a face split unui string.
std::vector<std::string> Utils::splitString(std::string &text, char delimiter) {
    std::vector<std::string> out;

    std::string::size_type beg = 0;
    for (auto end = 0; (end = text.find(delimiter, end)) != std::string::npos; ++end) {
        out.push_back(text.substr(beg, end - beg));
        beg = end + 1;
    }

    out.push_back(text.substr(beg));

    return out;
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
