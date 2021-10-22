//
// Created by NicolaeMarius.Ghergu on 10/22/2021.
//

#ifndef UTILITYIT_EVENT_H
#define UTILITYIT_EVENT_H

#include <iostream>

class Event {

private:
    std::string name;
    std::string description;
    long date;
    long duration;
    User peopleInvited[];
    User peopleJoined[];
    User peopleInterested[];

public:
    Event() {
    }
};

#endif //UTILITYIT_EVENT_H
