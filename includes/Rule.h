//
// Created by NicolaeMarius.Ghergu on 10/22/2021.
//

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

    Rule& operator=(const Rule& copie);
};

#endif //UTILITYIT_RULE_H
