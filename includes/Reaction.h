//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//
#pragma once

#ifndef UTILITYIT_REACTION_H
#define UTILITYIT_REACTION_H

#include <iostream>
#include "ReactionEnum.h"


enum class ReactionEnum;

class Reaction {

private:
    long id;
    std::shared_ptr<ReactionEnum> reactionType;

public:
    // constructor default
    Reaction() =default;

    // constructor de initializare
    Reaction(const long &id, std::shared_ptr<ReactionEnum> reactionType);

    // destructor
    ~Reaction();

    // constructor de copiere
    Reaction(const Reaction& copie);

    // operatorul =
    Reaction& operator=(const Reaction& copie);

    // operatorul <<
    friend std::ostream &operator<<(std::ostream &os, const Reaction &reaction);

    //TODO: add reaction to post
};


#endif //UTILITYIT_REACTION_H
