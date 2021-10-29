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
    Rule(long id, std::string text) : id(id), text(std::move(text)) {
        this->id = id;
        this->text = text;
    }

    long getId() const {
        return id;
    }

    void setId(long id) {
        this->id = id;
    }

    const std::string &getText() const {
        return text;
    }

    void setText(const std::string &text) {
        this->text = text;
    }
};

#endif //UTILITYIT_RULE_H
