//
// Created by nycuro on 10/30/21.
//

#include "../includes/Post.h"
#include "../includes/Utils.h"
#include "../includes/Application.h"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

class Utils;

class Application;

// Implementarea constructorului de initializare
Post::Post(const long &id, const std::string &description, const std::vector<std::shared_ptr<ReactionEnum>> &reactions,
           const std::vector<std::shared_ptr<Comment>> &comments, std::shared_ptr<User> createdBy,
           const long &creationDate) {
    std::cout << "[DEBUG] Apelare constructor Post.h" << std::endl;
    this->id = id;
    this->description = description;
    this->reactions = reactions;
    this->comments = comments;
    this->createdBy = std::move(createdBy);
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

void Post::setId(const long &id_) {
    this->id = id_;
}

void Post::createPost(User &user, const std::string &description) {
    std::ofstream file;
    std::ifstream readableOnly;
    std::string data;

    readableOnly.open("posts.txt", std::ios::in);

    int i = 1;
    while (getline(readableOnly, data)) {
        i++;
    }

    std::string id = std::to_string(i);

    data = id
            .append("|").append(description)
            .append("|")//reactions
            .append("|").append(user.getUsername())
            .append("|")//creation data
            ;

    file.open("posts.txt", std::ios::out | std::ios::app);

    file << std::endl << data;

    readableOnly.close();
    file.close();
}

void Post::handlePost(User &user) {
    std::cout << "Deci vrei sa creezi o postare. Am inteles. Pentru acest lucru, te rugam sa ne spui descrierea pe care doresti sa o adaugi postarii." << std::endl;
    std::string input;
    input = Utils::handleInput(input);
    createPost(user, input);
    std:: cout << "Postarea a fost creata cu succes!" << std::endl;
    Application::navigatePlatform(user);
}
