//
// Created by nycuro on 10/30/21.
//

#include "../includes/Event.h"

// Implementarea constructorului de initializare
Event::Event(const std::string &name, const std::string &description, const long &timestamp, const long &duration,
      const std::vector<User> &peopleInvited, const std::vector<User> &peopleJoined, const std::vector<User> &peopleInterested) {
    std::cout << "[DEBUG] Apelare constructor Event.h";
    this->name = name;
    this->description = description;
    this->timestamp = timestamp;
    this->duration = duration;
    this->peopleInvited = peopleInvited;
    this->peopleJoined = peopleJoined;
    this->peopleInterested = peopleInterested;
}

// Implementarea destructorului
Event::~Event() {
    std::cout << "[DEBUG] Apelare destructor Event.h";
}

// Implementarea constructorului de copiere
Event::Event(const Event &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Event.h";
    this->name = copie.name;
    this->description = copie.description;
    this->timestamp = copie.timestamp;
    this->duration = copie.duration;
    this->peopleInvited = copie.peopleInvited;
    this->peopleJoined = copie.peopleJoined;
    this->peopleInterested = copie.peopleInterested;
}

// Implementarea operatorului =
Event &Event::operator=(const Event &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere Event.h";
    this->name = copie.name;
    this->description = copie.description;
    this->timestamp = copie.timestamp;
    this->duration = copie.duration;
    this->peopleInvited = copie.peopleInvited;
    this->peopleJoined = copie.peopleJoined;
    this->peopleInterested = copie.peopleInterested;
    return *this;
}
