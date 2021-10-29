//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//

#ifndef UTILITYIT_POST_H
#define UTILITYIT_POST_H

#include <iostream>
#include "../interactions/Reaction.h"
#include "../interactions/Comment.h"
#include "enums/ReactionEnum.h"
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
    Post(long id, const std::string &name, const std::string &description, Reaction *reactions, Comment *comments,
         const User &createdBy, long creationDate) : id(id), name(name), description(description), reactions(reactions), comments(comments),
         createdBy(createdBy), creationDate(creationDate) {
        this->id = id;
        this->name = name;
        this->description = description;
        this->reactions = reactions;
        this->comments = comments;
        this->createdBy = createdBy;
        this->creationDate = creationDate;
    }

    long getId() const {
        return id;
    }

    void setId(long id) {
        this->id = id;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        this->name = name;
    }

    const std::string &getDescription() const {
        return description;
    }

    void setDescription(const std::string &description) {
        this->description = description;
    }

    Reaction *getReactions() const {
        return reactions;
    }

    void setReactions(Reaction *reactions) {
        this->reactions = reactions;
    }

    Comment *getComments() const {
        return comments;
    }

    void setComments(Comment *comments) {
        this->comments = comments;
    }

    const User &getCreatedBy() const {
        return createdBy;
    }

    void setCreatedBy(const User &createdBy) {
        this->createdBy = createdBy;
    }

    long getCreationDate() const {
        return creationDate;
    }

    void setCreationDate(long creationDate) {
        this->creationDate = creationDate;
    }

    void setReactions1(const std::vector<ReactionEnum> &reactions) {
        this->reactions = reactions;
    }

    void setComments1(const std::vector<Comment> &comments) {
        this->comments = comments;
    }
};


#endif //UTILITYIT_POST_H
