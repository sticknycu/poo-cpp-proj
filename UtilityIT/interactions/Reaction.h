//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//

#ifndef UTILITYIT_REACTION_H
#define UTILITYIT_REACTION_H

#include <iostream>
#include <filesystem>
#include "../entities/enums/ReactionEnum.h"

class Reaction {

private:
    long id;
    std::string name;

public:
    Reaction(long id, const std::string &name) : id(id), name(name) {
        this->id = id;
        this->name = name;
    }

    long getId() const {
        return id;
    }

    void setId(long id) {
        this->id = id;
    }

    std::string &getName() {
        std::string stringName;
        ReactionEnum reactionEnum = new ReactionEnum;
        for (int i = ReactionEnum; i != ReactionEnum::LAST_REACTION; i++) {
            auto reactionEnumCast = static_cast<ReactionEnum>(i);
            switch (reactionEnumCast) {
                case ReactionEnum::LIKE:
                    stringName = "Like";
                    break;
                case ReactionEnum::DISLIKE:
                    stringName = "Dislike";
                    break;
                case ReactionEnum::LOVE:
                    stringName = "Love";
                    break;
                case ReactionEnum::SAD:
                    stringName = "Sad";
                    break;
                case ReactionEnum::CRY:
                    stringName = "Cry";
                    break;
                case ReactionEnum::NERVOUS:
                    stringName = "Nervous";
                    break;
                case ReactionEnum::LAST_REACTION:
                    break;
            }
        }
        return &stringName; // ?? reference ??
    }
};


#endif //UTILITYIT_REACTION_H
