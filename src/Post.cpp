//
// Created by nycuro on 10/30/21.
//

#include "../includes/Post.h"

// Implementarea constructorului de initializare
Post::Post(const long &id, const std::string &description, const std::vector<ReactionEnum*> &reactions,
           const std::vector<Comment*> &comments, User* createdBy, const long &creationDate) {
    std::cout << "[DEBUG] Apelare constructor Post.h" << std::endl;
    this->id = id;
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
    this->description = copie.description;
    this->reactions = copie.reactions;
    this->comments = copie.comments;
    this->createdBy = copie.createdBy;
    this->creationDate = copie.creationDate;
}

// Implementarea operatorului =
Post &Post::operator=(const Post &copie) {
    std::cout << "[DEBUG] Apelare operator = Post.h" << std::endl;
    this->id = copie.id;
    this->description = copie.description;
    this->reactions = copie.reactions;
    this->comments = copie.comments;
    this->createdBy = copie.createdBy;
    this->creationDate = copie.creationDate;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Post &post) {
    std::cout << "[DEBUG] Apelare operator << Post.h" << std::endl;
    os << std::endl << post.id;
    os << std::endl << post.description;
    for (const auto &reaction : post.reactions) {
        os << std::endl << reaction;
    }
    for (const auto &comment : post.comments) {
        os << std::endl << comment;
    }
    os << std::endl << post.createdBy;
    os << std::endl << post.creationDate;
    return os;
}

long &Post::getId() {
    return this->id;
}

void Post::setId(const long &id) {
    this->id = id;
}
