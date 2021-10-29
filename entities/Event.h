//
// Created by NicolaeMarius.Ghergu on 10/22/2021.
//

#ifndef UTILITYIT_EVENT_H
#define UTILITYIT_EVENT_H

#include <iostream>
#include "User.h"
#include <vector>

class Event {

private:
    std::string name;
    std::string description;
    long date;
    long duration;
    std::vector<User> peopleInvited;
    std::vector<User> peopleJoined;
    std::vector<User> peopleInterested;
public:

    Event(const std::string &name, const std::string &description, long date, long duration, const std::vector<User> &peopleInvited,
          std::vector<User> &peopleJoined, std::vector<User> &peopleInterested) : name(name), description(description), date(date),
                                                        duration(duration), peopleInvited(peopleInvited),
                                                        peopleJoined(peopleJoined),
                                                        peopleInterested(peopleInterested) {
        this->name = name;
        this->description = description;
        this->date = date;
        this->duration = duration;
        this->peopleInvited = peopleInvited;
        this->peopleJoined = peopleJoined;
        this->peopleInvited = peopleInterested;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        this->name = name;
    }

    const std::string &getDescription() const {
        return description;
    }

    void setDescription(const std::string &description) {
        this->description = description;
    }

    long getDate() const {
        return date;
    }

    void setDate(long date) {
        this->date = date;
    }

    long getDuration() const {
        return duration;
    }

    void setDuration(long duration) {
        this->duration = duration;
    }

    const std::vector<User> &getPeopleInvited() const {
        return peopleInvited;
    }

    void setPeopleInvited(const std::vector<User> &peopleInvited) {
        this->peopleInvited = peopleInvited;
    }

    const std::vector<User> &getPeopleJoined() const {
        return peopleJoined;
    }

    void setPeopleJoined(const std::vector<User> &peopleJoined) {
        this->peopleJoined = peopleJoined;
    }

    const std::vector<User> &getPeopleInterested() const {
        return peopleInterested;
    }

    void setPeopleInterested(const std::vector<User> &peopleInterested) {
        this->peopleInterested = peopleInterested;
    }

};

#endif //UTILITYIT_EVENT_H
