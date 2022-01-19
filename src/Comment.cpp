//
// Created by nycuro on 10/29/21.
//

#include "../includes/Comment.h"
#include "../includes/Utils.h"
#include "../includes/Application.h"
#include <fstream>
#include <string>
#include <utility>

class Utils;
class Application;

// Implementarea constructorului de initializare
Comment::Comment(const long &id, std::shared_ptr<User> createdBy, const long &creationDate, const std::string &text, std::shared_ptr<Post> post) {
    std::cout << "[DEBUG] Apelare constructor Comment.h" << std::endl;
    this->id = id;
    this->createdBy = std::move(createdBy);
    this->creationDate = creationDate;
    this->text = text;
    this->post = std::move(post);
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

std::shared_ptr<User> Comment::getCreatedBy() {
    return this->createdBy;
}

void Comment::setCreatedBy(std::shared_ptr<User> user) {
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

std::shared_ptr<Post> Comment::getPost() {
    return this->post;
}

void Comment::setPost(std::shared_ptr<Post> post_) {
    this->post = post_;
}

void Comment::handleComment(User &user) {
    std::cout << "Pentru a adauga un comentariu, te rugam sa ne spui textul pe care trebuie sa-l contina:" << std::endl;
    std::string input;
    input = Utils::handleInput(input);
    std::string localInput;
    std::cout
            << "De asemenea, trebuie sa stim si id-ul postarii. Il poti afla la navigarea platformei folosind /idMyPosts sau /idPosts"
            << std::endl;
    while (std::cin >> localInput) {
        if (localInput == "/idMyPosts" || localInput == "/idPosts") {
            std::cout << "Te rugam sa introduci aceasta comanda in navigarea platformei. Deocamdata dorim un ID."
                      << std::endl;
            std::cout << "In cazul in care nu ai unul, te rugam sa revii la navigarea platformei cu /exit" << std::endl;
        } else if (localInput == "/exit") {
            Application::navigatePlatform(user);
        } else {
            long id = std::stol(localInput);
            createComment(user, input, id);
        }
    }
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
