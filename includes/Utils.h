//
// Created by nycuro on 10/30/21.
//
#pragma once

#ifndef UTILITYIT_UTILS_H
#define UTILITYIT_UTILS_H

#include <iostream>
#include <vector>

class Utils {
public:

    Utils() = delete;

    Utils(const Utils&) = delete;

    // operatorul =
    Utils& operator=(const Utils&) = delete;

    // Implementarea pentru a face split al unui string.
    static std::vector<std::string> splitString(std::string &text, char delimiter);

    // Handle string when is shit and don't want to
    static const std::string& handleInput(std::string &text);

    static long getCurrentTime();
};

#endif //UTILITYIT_UTILS_H
