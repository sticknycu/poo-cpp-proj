//
// Created by nycuro on 10/29/21.
//

#include "../includes/Comment.h"

// Implementarea constructorului de initializare
Comment::Comment(const long &id, User *createdBy, const long &creationDate, const std::string &text) {
    std::cout << "[DEBUG] Apelare constructor Comment.h";
    this->id = id;
    this->createdBy = createdBy;
    this->creationDate = creationDate;
    this->text = text;
}

// Implementarea destructorului
Comment::~Comment() {
    std::cout << "[DEBUG] Apelare destructor Comment.h";
}

// Implementarea constructorului de copiere
Comment::Comment(const Comment &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Comment.h";
    this->id = copie.id;
    this->text = copie.text;
    this->creationDate = copie.creationDate;
    this->createdBy = copie.createdBy;
}

// Implementarea operatorului =
Comment &Comment::operator=(const Comment &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Comment.h";
    this->id = copie.id;
    this->text = copie.text;
    this->creationDate = copie.creationDate;
    this->createdBy = copie.createdBy;
    return *this;
}
