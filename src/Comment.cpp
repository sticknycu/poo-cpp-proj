//
// Created by nycuro on 10/29/21.
//

#include "../includes/Comment.h"

// Implementarea constructorului de initializare
Comment::Comment(const long &id, User *createdBy, const long &creationDate, const std::string &text, Post *post) {
    std::cout << "[DEBUG] Apelare constructor Comment.h" << std::endl;
    this->id = id;
    this->createdBy = createdBy;
    this->creationDate = creationDate;
    this->text = text;
    this->post = post;
}

// Implementarea destructorului
Comment::~Comment() {
    std::cout << "[DEBUG] Apelare destructor Comment.h" << std::endl;
}

// Implementarea constructorului de copiere
Comment::Comment(const Comment &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Comment.h" << std::endl;
    this->id = copie.id;
    this->text = copie.text;
    this->creationDate = copie.creationDate;
    this->createdBy = copie.createdBy;
    this->post = copie.post;
}

// Implementarea operatorului =
Comment &Comment::operator=(const Comment &copie) {
    std::cout << "[DEBUG] Apelare operator = Comment.h" << std::endl;
    this->id = copie.id;
    this->text = copie.text;
    this->creationDate = copie.creationDate;
    this->createdBy = copie.createdBy;
    this->post = copie.post;
    return *this;
}

// Implementarea operatorului <<
std::ostream &operator<<(std::ostream &os, const Comment &comment) {
    std::cout << "[DEBUG] Apelare operator << Comment.h" << std::endl;
    os << std::endl << comment.id;
    os << std::endl << comment.text;
    os << std::endl << comment.createdBy;
    os << std::endl << comment.creationDate;
    os << std::endl << comment.post;
    return os;
}
