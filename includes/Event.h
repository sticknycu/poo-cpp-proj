//
// Created by NicolaeMarius.Ghergu on 10/22/2021.
//
#pragma once

#ifndef UTILITYIT_EVENT_H
#define UTILITYIT_EVENT_H

#include <iostream>
#include "User.h"
#include <vector>

class Event {

private:
    std::string name;
    std::string description;
    long timestamp;
    long duration;
    std::vector<User> peopleInvited;
    std::vector<User> peopleJoined;
    std::vector<User> peopleInterested;

public:

    // constructor default
    Event() =default;

    // constructor de initializare
    Event(const std::string &name, const std::string &description, const long &timestamp, const long &duration,
          const std::vector<User> &peopleInvited, const std::vector<User> &peopleJoined, const std::vector<User> &peopleInterested);

    // destructor
    ~Event();

    // constructor de copiere
    Event(const Event& copie);

    Event& operator=(const Event& copie);

};

#endif //UTILITYIT_EVENT_H
