//
// Created by NicolaeMarius.Ghergu on 10/22/2021.
//

#ifndef UTILITYIT_GROUP_H
#define UTILITYIT_GROUP_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Rule.h"
#include "Post.h"

class Group {
private:
    std::vector<User> peopleJoined;
    std::vector<User> peopleRequestedToJoin;
    std::string description;
    std::vector<Rule> rules;
    std::vector<Post> posts;

public:
    Group(std::vector<User> &peopleJoined, std::vector<User> &peopleRequestedToJoin, const std::string &description, std::vector<Rule> &rules,
          std::vector<Post> &posts) {
        this->peopleJoined = peopleJoined;
        this->peopleRequestedToJoin = peopleRequestedToJoin;
        this->description = description;
        this->rules = rules;
        this->posts = posts;
    }

    const std::vector<User> &getPeopleJoined() const {
        return peopleJoined;
    }

    void setPeopleJoined(const std::vector<User> &peopleJoined) {
        this->peopleJoined = peopleJoined;
    }

    const std::vector<User> &getPeopleRequestedToJoin() const {
        return peopleRequestedToJoin;
    }

    void setPeopleRequestedToJoin(const std::vector<User> &peopleRequestedToJoin) {
        this->peopleRequestedToJoin = peopleRequestedToJoin;
    }

    const std::string &getDescription() const {
        return description;
    }

    void setDescription(const std::string &description) {
        this->description = description;
    }

    const std::vector<Rule> &getRules() const {
        return rules;
    }

    void setRules(const std::vector<Rule> &rules) {
        this->rules = rules;
    }

    const std::vector<Post> &getPosts() const {
        return posts;
    }

    void setPosts(const std::vector<Post> &posts) {
        this->posts = posts;
    }
};

#endif //UTILITYIT_GROUP_H