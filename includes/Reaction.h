//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//
#pragma once

#ifndef UTILITYIT_REACTION_H
#define UTILITYIT_REACTION_H

#include <iostream>
#include <filesystem>
#include "ReactionEnum.h"

class Reaction {

private:
    long id;
    std::string name;

public:
    // constructor default
    Reaction() =default;

    // constructor de initializare
    Reaction(const long &id, const std::string &name);

    // destructor
    ~Reaction();

    // constructor de copiere
    Reaction(const Reaction& copie);

    Reaction& operator=(const Reaction& copie);

    /*std::string &getName() {
        std::string stringName;
        ReactionEnum reactionEnum;
        for (auto i = ReactionEnum::LIKE; i != ReactionEnum::LAST_REACTION; i++) {
            auto reactionEnumCast = static_cast<ReactionEnum>(i);
            switch (reactionEnumCast) {
                case ReactionEnum::LIKE:
                    stringName = "Like" << std::endl;
                    break;
                case ReactionEnum::DISLIKE:
                    stringName = "Dislike" << std::endl;
                    break;
                case ReactionEnum::LOVE:
                    stringName = "Love" << std::endl;
                    break;
                case ReactionEnum::SAD:
                    stringName = "Sad" << std::endl;
                    break;
                case ReactionEnum::CRY:
                    stringName = "Cry" << std::endl;
                    break;
                case ReactionEnum::NERVOUS:
                    stringName = "Nervous" << std::endl;
                    break;
                case ReactionEnum::LAST_REACTION:
                    break;
            }
        }
        return stringName; // ?? reference ??
    }*/
};


#endif //UTILITYIT_REACTION_H
