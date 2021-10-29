//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//

#ifndef UTILITYIT_COMMENT_H
#define UTILITYIT_COMMENT_H

#include <iostream>
#include <utility>
#include "../entities/User.h"

class Comment {
private:
    long id;
    User createdBy;
    long creationDate;
    std::string text;

public:
    Comment(long id, User createdBy, long creationDate, std::string text) : id(id), createdBy(std::move(createdBy)),
                                                                                          creationDate(creationDate),
                                                                                          text(std::move(text)) {
        this->id = id;
        this->createdBy = createdBy;
        this->text = text;
    }

    long getId() const {
        return id;
    }

    void setId(long id) {
        this->id = id;
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

    const std::string &getText() const {
        return text;
    }

    void setText(const std::string &text) {
        this->text = text;
    }
};


#endif //UTILITYIT_COMMENT_H
