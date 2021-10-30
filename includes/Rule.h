//
// Created by NicolaeMarius.Ghergu on 10/22/2021.
//
#pragma once

#ifndef UTILITYIT_RULE_H
#define UTILITYIT_RULE_H

#include <iostream>
#include <utility>

class Rule {

private:
    long id;
    std::string text;
public:
    // constructor default
    Rule() =default;

    // constructor de initializare
    Rule(const long &id, const std::string &text);

    // destructor
    ~Rule();

    // constructor de copiere
    Rule(const Rule& copie);

    // operatorul =
    Rule& operator=(const Rule& copie);

    // operatorul <<
    friend std::ostream &operator<<(std::ostream &os, const Rule &rule);
};

#endif //UTILITYIT_RULE_H
