//
// Created by nycuro on 10/30/21.
//

#include "../includes/ReactionEnum.h"
#include <iostream>

// Implementarea operatorului <<
std::ostream &operator<<(std::ostream &os, ReactionEnum &reactionType) {
    std::cout << "[DEBUG] Apelare operator << ReactionEnum.h" << std::endl;
    switch (reactionType) {
        case ReactionEnum::LIKE:
            os << std::endl << "Like";
            break;
        case ReactionEnum::DISLIKE:
            os << std::endl << "Dislike";
            break;
        case ReactionEnum::LOVE:
            os << std::endl << "Love";
            break;
        case ReactionEnum::SAD:
            os << std::endl << "Sad";
            break;
        case ReactionEnum::CRY:
            os << std::endl << "Cry";
            break;
        case ReactionEnum::NERVOUS:
            os << std::endl << "Nervous";
            break;
    }
    return os;
}
