//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//

#ifndef UTILITYIT_REACTION_H
#define UTILITYIT_REACTION_H

#include <iostream>
#include <filesystem>

class Reaction {

private:
    long id;
    std::string name;
    std::filesystem location;

public:

    Reaction() {
    }

    long getId() {
        return this->id;
    }

    void setId(long id) {
        this->id = id;
    }

    std::string getName() {
        return this->name;
    }

    void setName(std::string name) {
        this->name = name;
    }

    std::filesystem getLocation() {
        return this->location;
    }

    void setLocation(std::filesystem location) {
        this->location = location;
    }
};


#endif //UTILITYIT_REACTION_H
