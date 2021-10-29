//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//

#ifndef UTILITYIT_POST_H
#define UTILITYIT_POST_H

#include <iostream>
#include "Comment.h"
#include "Reaction.h"
#include "Post.h"
#include "ReactionEnum.h"
#include <vector>

class Post {
private:
    long id;
    std::string name;
    std::string description;
    std::vector<ReactionEnum> reactions;
    std::vector<Comment> comments;
    User createdBy;
    long creationDate;

public:
    // constructor default
    Post() =default;

    // constructor de initializare
    Post(const long &id, const std::string &name, const std::string &description, const std::vector<ReactionEnum> &reactions,
         const std::vector<Comment> &comments, const User &createdBy, const long &creationDate);

    // destructor
    ~Post();

    // constructor de copiere
    Post(const Post& copie);

    Post& operator=(const Post& copie);
};


#endif //UTILITYIT_POST_H
