//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//

#ifndef UTILITYIT_COMMENT_H
#define UTILITYIT_COMMENT_H

#include <iostream>
#include "../entities/User.h"

class Comment {
private:
    long id;
    User createdBy;
    long creationDate;
    std::string text;

public:

    Comment() {
    }

    long getId() {
        return this->id;
    }

    void setId(long id) {
        this->id = id;
    }

    User getCreatedBy() {
        return this->createdBy;
    }

    void setCreatedBy(User user) {
        this->user = user;
    }

    long getCreationDate() {
        return this->creationDate;
    }

    void setCreationDate(long creationDate) {
        this->creationDate = creationDate;
    }

    std::string getText() {
        return this->text;
    }

    void setText(std::string text) {
        this->text = text;
    }
};


#endif //UTILITYIT_COMMENT_H
