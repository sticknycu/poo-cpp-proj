//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//
#pragma once

#ifndef UTILITYIT_REACTION_H
#define UTILITYIT_REACTION_H

#include <iostream>
#include "ReactionEnum.h"
#include <memory>

enum class ReactionEnum;

class Reaction {

    friend class ReactionBuilder;

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

class ReactionBuilder {
private:

    Reaction reaction;

public:
    ReactionBuilder() = default;

    ReactionBuilder& id(long id) {
        reaction.id = id;
        return *this;
    }

    ReactionBuilder& reactionType(std::shared_ptr<ReactionEnum> reactionType) {
        reaction.reactionType = reactionType;
        return *this;
    }

    Reaction build() {
        return reaction;
    }
};


#endif //UTILITYIT_REACTION_H
