//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//
#pragma once

#ifndef UTILITYIT_COMMENT_H
#define UTILITYIT_COMMENT_H

#include <iostream>
#include "User.h"

class User;
class Post;

class Comment {
private:
    long id;
    User createdBy;
    long creationDate;
    static std::string text;
    Post post;

public:

    // constructor default
    Comment() =default;

    // constructor de initializare
    Comment(const long &id, User &createdBy, const long &creationDate, const std::string &text, Post &post);

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

    User &getCreatedBy();

    void setCreatedBy(User &user);

    long &getCreationDate();

    void setCreationDate(const long &timestamp);

    std::string &getText();

    void setText(const std::string &text);

    Post &getPost();

    void setPost(Post &post);

    // function to handle comments
    static void handleComment(User &user);

    // function to add comments to file
    static void createComment(User &user, const std::string &text, const long &id);
};

#endif //UTILITYIT_COMMENT_H
