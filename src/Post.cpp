//
// Created by nycuro on 10/30/21.
//

#include "../includes/Post.h"

// Implementarea constructorului de initializare
Post::Post(const long &id, const std::string &name, const std::string &description, const std::vector<ReactionEnum*> &reactions,
           const std::vector<Comment*> &comments, User* createdBy, const long &creationDate) {
    std::cout << "[DEBUG] Apelare constructor Post.h" << std::endl;
    this->id = id;
    this->name = name;
    this->description = description;
    this->reactions = reactions;
    this->comments = comments;
    this->createdBy = createdBy;
    this->creationDate = creationDate;
}

// Implementarea destructorului
Post::~Post() {
    std::cout << "[DEBUG] Apelare destructor Post.h" << std::endl;
}

// Implementarea constructorului de copiere
Post::Post(const Post &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Post.h" << std::endl;
    this->id = copie.id;
    this->name = copie.name;
    this->description = copie.description;
    this->reactions = copie.reactions;
    this->comments = copie.comments;
    this->createdBy = copie.createdBy;
    this->creationDate = copie.creationDate;
}

// Implementarea operatorului =
Post &Post::operator=(const Post &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Post.h" << std::endl;
    this->id = copie.id;
    this->name = copie.name;
    this->description = copie.description;
    this->reactions = copie.reactions;
    this->comments = copie.comments;
    this->createdBy = copie.createdBy;
    this->creationDate = copie.creationDate;
    return *this;
}
