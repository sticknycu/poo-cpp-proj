//
// Created by nycuro on 10/29/21.
//

#include "../includes/Comment.h"
#include "../includes/Utils.h"
#include <fstream>

// Implementarea constructorului de initializare
Comment::Comment(const long &id, User* createdBy, const long &creationDate, const std::string &text, Post* post) {
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

long &Comment::getId() {
    return this->id;
}

void Comment::setId(const long &id) {
    this->id = id;
}

User* Comment::getCreatedBy() {
    return this->createdBy;
}

void Comment::setCreatedBy(User* user) {
    this->createdBy = user;
}

long &Comment::getCreationDate() {
    return this->creationDate;
}

void Comment::setCreationDate(const long &timestamp) {
    this->creationDate = timestamp;
}

std::string &Comment::getText() {
    return this->text;
}

void Comment::setText(const std::string &text) {
    this->text = text;
}

Post* Comment::getPost() {
    return this->post;
}

void Comment::setPost(Post* post) {
    this->post = post;
}

void Comment::handleComment(User &user) {
    std::cout << "Pentru a adauga un comentariu, te rugam sa ne spui textul pe care trebuie sa-l contina:" << std::endl;
    std::string input;
    input = Utils::handleInput(input);
    long id;
    std::cout << "De asemenea, trebuie sa stim si id-ul postarii. Il poti afla la navigarea platformei folosind /idMyPosts sau /idPosts" << std::endl;
    std::cin >> id;
    createComment(user, input, id);
    Utils::navigatePlatform(user);
}

void Comment::createComment(User &user, const std::string &text, const long &id) {
    std::ofstream file;
    std::ifstream readableOnly;
    std::string data;

    readableOnly.open("comments.txt", std::ios::in);

    int i = 1;
    while (getline(readableOnly, data)) {
        i++;
    }

    std::string stringI = std::to_string(i);

    data = stringI
            .append("|").append(user.getUsername())
            .append("|").append(std::to_string(Utils::getCurrentTime()))
            .append("|").append(text)
            .append("|").append(std::to_string(id))
            ;

    file.open("comments.txt", std::ios::out | std::ios::app);

    file << std::endl << data;

    readableOnly.close();
    file.close();
}
