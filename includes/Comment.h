//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//
#pragma once

#ifndef UTILITYIT_COMMENT_H
#define UTILITYIT_COMMENT_H

#include <iostream>
#include "User.h"
#include <memory>

class User;
class Post;

class Comment {
private:
    long id;
    std::shared_ptr<User> createdBy;
    long creationDate;
    std::string text;
    std::shared_ptr<Post> post;

public:

    // constructor default
    Comment() =default;

    // constructor de initializare
    Comment(const long &id, std::shared_ptr<User> createdBy, const long &creationDate, const std::string &text, std::shared_ptr<Post> post);

    // destructor
    ~Comment();

    // constructor de copiere
    Comment(const Comment& copie);

    // operatorul =
    Comment& operator=(const Comment& copie);

    // operatorul <<
    friend std::ostream &operator<<(std::ostream &os, const Comment &comment);

    long &getId();

    void setId(const long &id);

    std::shared_ptr<User> getCreatedBy();

    void setCreatedBy(std::shared_ptr<User> user);

    long &getCreationDate();

    void setCreationDate(const long &timestamp);

    std::string &getText();

    void setText(const std::string &text);

    std::shared_ptr<Post> getPost();

    void setPost(std::shared_ptr<Post> post);

    // function to handle comments
    static void handleComment(User &user);

    // function to add comments to file
    static void createComment(User &user, const std::string &text, const long &id);
};

#endif //UTILITYIT_COMMENT_H
