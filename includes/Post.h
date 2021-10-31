//
// Created by NicolaeMarius.Ghergu on 10/21/2021.
//
#pragma once

#ifndef UTILITYIT_POST_H
#define UTILITYIT_POST_H

#include <iostream>
#include "Comment.h"
#include "ReactionEnum.h"
#include <vector>

enum class ReactionEnum;
class Comment;
class User;

class Post {
private:
    long id;
    std::string description;
    std::vector<ReactionEnum*> reactions;
    std::vector<Comment*> comments;
    User *createdBy;
    long creationDate;

public:
    // constructor default
    Post() =default;

    // constructor de initializare
    Post(const long &id, const std::string &description, const std::vector<ReactionEnum*> &reactions,
         const std::vector<Comment*> &comments, User* createdBy, const long &creationDate);

    // destructor
    ~Post();

    // constructor de copiere
    Post(const Post& copie);

    // operatorul =
    Post& operator=(const Post& copie);

    // operatorul <<
    friend std::ostream &operator<<(std::ostream &os, const Post &post);

    long &getId();

    void setId(const long &id);

    // Handle post when is going to be created
    static void handlePost(User &user);

    // Handle post of user. Function for save post information of user in file
    static void createPost(User &user, const std::string &description);

    // Handle post of user. Function for delete post information of user in file
    static void deletePost(const long &id);

    // Handle posts of user. Show posts of a user
    static void showPostsUser(User &user);

    // Handle posts. Show all posts
    static void showPosts();
};


#endif //UTILITYIT_POST_H
