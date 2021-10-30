//
// Created by nycuro on 10/22/21.
//
#pragma once

#ifndef UTILITYIT_REACTIONENUM_H
#define UTILITYIT_REACTIONENUM_H

#include <ostream>

enum class ReactionEnum {
    LIKE,
    DISLIKE,
    LOVE,
    SAD,
    CRY,
    NERVOUS
};

std::ostream &operator<<(std::ostream &os, ReactionEnum reactionType);

#endif //UTILITYIT_REACTIONENUM_H
